    RH *handler;
} authenticateStateData;

typedef struct _authenticator {
    int index;
    helper_flags flags;
    int fd;
    char *inbuf;
    unsigned int size;
    unsigned int offset;
    struct timeval dispatch_time;
    authenticateStateData *authenticateState;
} authenticator_t;

static struct {
    int requests;
    int replies;
    int errors;
    int avg_svc_time;
    int queue_size;
    int use_hist[DefaultAuthenticateChildrenMax];
    int rewrites[DefaultAuthenticateChildrenMax];
} AuthenticateStats;


struct authenticateQueueData {
    struct authenticateQueueData *next;
    authenticateStateData *authenticateState;
};

static authenticator_t *GetFirstAvailable(void);
static PF authenticateHandleRead;
static authenticateStateData *Dequeue(void);
static void Enqueue(authenticateStateData *);
static void authenticateDispatch(authenticator_t *, authenticateStateData *);
static void authenticateStateFree(authenticateStateData * r);

static authenticator_t **authenticate_child_table = NULL;
static int NAuthenticators = 0;
static int NAuthenticatorsOpen = 0;
static struct authenticateQueueData *authenticateQueueHead = NULL;
static struct authenticateQueueData **authenticateQueueTailP = &authenticateQueueHead;

static void
authenticateHandleRead(int fd, void *data)
{
    authenticator_t *authenticator = data;
    int len;
    authenticateStateData *r = authenticator->authenticateState;
    char *t = NULL;
    int n;

    Counter.syscalls.sock.reads++;
    len = read(fd,
	authenticator->inbuf + authenticator->offset,
	authenticator->size - authenticator->offset);
    fd_bytes(fd, len, FD_READ);
    debug(29, 5) ("authenticateHandleRead: %d bytes from Authenticator #%d.\n",
	len, authenticator->index + 1);
    if (len <= 0) {
	if (len < 0)
	    debug(50, 1) ("authenticateHandleRead: FD %d read: %s\n", fd, xstrerror());
	debug(29, authenticator->flags.closing ? 5 : 1)
	    ("FD %d: Connection from Authenticator #%d is closed, disabling\n",
	    fd, authenticator->index + 1);
	authenticator->flags.alive = 0;
	authenticator->flags.busy = 0;
	authenticator->flags.closing = 0;
	authenticator->flags.shutdown = 0;
	memFree(MEM_8K_BUF, authenticator->inbuf);
	authenticator->inbuf = NULL;
	comm_close(fd);
	if (--NAuthenticatorsOpen == 0 && !shutting_down)
	    fatal_dump("All authenticators have exited!");
	return;
    }
    if (len != 1)
	AuthenticateStats.rewrites[authenticator->index]++;
    authenticator->offset += len;
    authenticator->inbuf[authenticator->offset] = '\0';
    /* reschedule */
    commSetSelect(authenticator->fd,
	COMM_SELECT_READ,
	authenticateHandleRead,
	authenticator, 0);
    if ((t = strchr(authenticator->inbuf, '\n'))) {
	/* end of record found */
	*t = '\0';
	if ((t = strchr(authenticator->inbuf, ' ')))
	    *t = '\0';		/* terminate at space */
	if (r == NULL) {
	    /* A naughty authenticator has spoken without being spoken to */
	    /* B.R.Foster@massey.ac.nz, SQUID/1.1.3 */
	    debug(29, 0) ("authenticateHandleRead: unexpected reply: '%s'\n",
		authenticator->inbuf);
	    authenticator->offset = 0;
	} else {
	    debug(29, 5) ("authenticateHandleRead: reply: '%s'\n",
		authenticator->inbuf);
	    /* careful here.  r->data might point to something which
	     * has recently been freed.  If so, we require that r->handler
	     * be NULL */
	    if (r->handler) {
		r->handler(r->data,
		    t == authenticator->inbuf ? NULL : authenticator->inbuf);
	    }
	    authenticateStateFree(r);
	    authenticator->authenticateState = NULL;
	    authenticator->flags.busy = 0;
	    authenticator->offset = 0;
	    n = ++AuthenticateStats.replies;
	    AuthenticateStats.avg_svc_time =
		intAverage(AuthenticateStats.avg_svc_time,
		tvSubMsec(authenticator->dispatch_time, current_time),
		n, AUTHENTICATE_AV_FACTOR);
	}
    }
    while ((authenticator = GetFirstAvailable()) && (r = Dequeue()))
	authenticateDispatch(authenticator, r);
}

static void
Enqueue(authenticateStateData * r)
{
    struct authenticateQueueData *new = xcalloc(1, sizeof(struct authenticateQueueData));
    new->authenticateState = r;
    *authenticateQueueTailP = new;
    authenticateQueueTailP = &new->next;
    AuthenticateStats.queue_size++;
}

static authenticateStateData *
Dequeue(void)
{
    struct authenticateQueueData *old = NULL;
    authenticateStateData *r = NULL;
    if (authenticateQueueHead) {
	r = authenticateQueueHead->authenticateState;
	old = authenticateQueueHead;
	authenticateQueueHead = authenticateQueueHead->next;
	if (authenticateQueueHead == NULL)
	    authenticateQueueTailP = &authenticateQueueHead;
	safe_free(old);
	AuthenticateStats.queue_size--;
    }
    return r;
}

static authenticator_t *
GetFirstAvailable(void)
{
    int k;
    authenticator_t *authenticate = NULL;
    for (k = 0; k < NAuthenticators; k++) {
	authenticate = *(authenticate_child_table + k);
	if (authenticate->flags.busy)
	    continue;
	if (!authenticate->flags.alive)
	    continue;
	return authenticate;
    }
    return NULL;
}

static void
authenticateStateFree(authenticateStateData * r)
{
    safe_free(r);
}


static void
authenticateDispatch(authenticator_t * authenticate, authenticateStateData * r)
{
    char *buf = NULL;
    int len;
    if (r->handler == NULL) {
	debug(29, 1) ("authenticateDispatch: skipping '%s' because no handler\n",
	    r->auth_user->user);
	authenticateStateFree(r);
	return;
    }
    authenticate->flags.busy = 1;
    authenticate->authenticateState = r;
    authenticate->dispatch_time = current_time;
    buf = memAllocate(MEM_8K_BUF);
    snprintf(buf, 8192, "%s %s\n",
	r->auth_user->user,
	r->auth_user->passwd);
    len = strlen(buf);
    comm_write(authenticate->fd,
	buf,
	len,
	NULL,			/* Handler */
	NULL,			/* Handler-data */
	memFree8K);
    debug(29, 5) ("authenticateDispatch: Request sent to Authenticator #%d, %d bytes\n",
	authenticate->index + 1, len);
    AuthenticateStats.use_hist[authenticate->index]++;
    AuthenticateStats.requests++;
}


/**** PUBLIC FUNCTIONS ****/


void
authenticateStart(acl_proxy_auth_user * auth_user, RH * handler, void *data)
{
    authenticateStateData *r = NULL;
    authenticator_t *authenticator = NULL;
    if (!auth_user)
	fatal_dump("authenticateStart: NULL auth_user");
    if (!handler)
	fatal_dump("authenticateStart: NULL handler");
    debug(29, 5) ("authenticateStart: '%s:%s'\n", auth_user->user,
	auth_user->passwd);
    if (Config.Program.authenticate == NULL) {
	handler(data, NULL);
	return;
    }
    r = xcalloc(1, sizeof(authenticateStateData));
    r->handler = handler;
    r->data = data;
    r->auth_user = auth_user;
    if ((authenticator = GetFirstAvailable()))
	authenticateDispatch(authenticator, r);
    else
	Enqueue(r);
}

void
authenticateFreeMemory(void)
{
    int k;
    /* free old structures if present */
    if (authenticate_child_table) {
	for (k = 0; k < NAuthenticators; k++) {
	    if (authenticate_child_table[k]->inbuf)
		memFree(MEM_8K_BUF, authenticate_child_table[k]->inbuf);
	    safe_free(authenticate_child_table[k]);
	}
	safe_free(authenticate_child_table);
    }
}

void
authenticateOpenServers(void)
{
    char *prg;
    wordlist *auth_opts;
    char *short_prg;
    char *short_prg2;
    int k;
    int authenticatesocket;
    LOCAL_ARRAY(char, fd_note_buf, FD_DESC_SZ);
    static int first_time = 0;
    char *s;
    char *args[32];
    int i, x;

    authenticateFreeMemory();
    if (Config.Program.authenticate == NULL)
	return;
    prg = Config.Program.authenticate->key;
    NAuthenticators = NAuthenticatorsOpen = Config.authenticateChildren;
    authenticate_child_table = xcalloc(NAuthenticators, sizeof(authenticator_t *));
    debug(29, 1) ("authenticateOpenServers: Starting %d '%s' processes\n",
	NAuthenticators, prg);
    if ((s = strrchr(prg, '/')))
	short_prg = xstrdup(s + 1);
    else
	short_prg = xstrdup(prg);
    short_prg2 = xmalloc(strlen(s) + 3);
    snprintf(short_prg2, strlen(s) + 3, "(%s)", short_prg);
    for (k = 0; k < NAuthenticators; k++) {
	authenticate_child_table[k] = xcalloc(1, sizeof(authenticator_t));
	args[0] = short_prg2;
	i = 1;
	auth_opts = Config.Program.authenticate->next;
	while ((auth_opts != NULL) && (i < 31)) {
	    args[i++] = auth_opts->key;
	    auth_opts = auth_opts->next;
	}
	if (auth_opts != NULL) {
	    debug(29, 0) ("WARNING: too many authenticate_options\n");
	}
	args[i] = NULL;
	x = ipcCreate(IPC_TCP_SOCKET,
	    prg,
	    args,
	    "authenticator",
	    &authenticatesocket,
	    &authenticatesocket);
	if (x < 0) {
	    debug(29, 1) ("WARNING: Cannot run '%s' process.\n", prg);
	    authenticate_child_table[k]->flags.alive = 0;
	} else {
	    authenticate_child_table[k]->flags.alive = 1;
	    authenticate_child_table[k]->index = k;
	    authenticate_child_table[k]->fd = authenticatesocket;
	    authenticate_child_table[k]->inbuf = memAllocate(MEM_8K_BUF);
	    authenticate_child_table[k]->size = 8192;
	    authenticate_child_table[k]->offset = 0;
	    snprintf(fd_note_buf, FD_DESC_SZ, "%s #%d",
		short_prg,
		authenticate_child_table[k]->index + 1);
	    fd_note(authenticate_child_table[k]->fd, fd_note_buf);
	    commSetNonBlocking(authenticate_child_table[k]->fd);
	    /* set handler for incoming result */
	    commSetSelect(authenticate_child_table[k]->fd,
		COMM_SELECT_READ,
		authenticateHandleRead,
		authenticate_child_table[k], 0);
	    debug(29, 3) ("authenticateOpenServers: 'authenticate_server' %d started\n",
		k);
	}
    }
    if (first_time == 0) {
	first_time++;
	memset(&AuthenticateStats, '\0', sizeof(AuthenticateStats));
	cachemgrRegister("authenticator",
	    "Authenticator Stats",
	    authenticateStats, 0, 1);
    }
    safe_free(short_prg);
    safe_free(short_prg2);
}

void
authenticateShutdownServers(void *unused)
{
    authenticator_t *authenticate = NULL;
    authenticateStateData *r = NULL;
    int k;
    int na = 0;
    if (Config.Program.authenticate == NULL)
	return;
    if (authenticateQueueHead) {
	while ((authenticate = GetFirstAvailable()) && (r = Dequeue()))
	    authenticateDispatch(authenticate, r);
	return;
    }
    for (k = 0; k < NAuthenticators; k++) {
	authenticate = *(authenticate_child_table + k);
	if (!authenticate->flags.alive)
	    continue;
	if (authenticate->flags.closing)
	    continue;
	if (authenticate->flags.busy) {
	    na++;
	    continue;
	}
	debug(29, 3) ("authenticateShutdownServers: closing authenticator #%d, FD %d\n",
	    authenticate->index + 1, authenticate->fd);
	comm_close(authenticate->fd);
	authenticate->flags.closing = 1;
	authenticate->flags.busy = 1;
    }
    if (na)
	eventAdd("authenticateShutdownServers", authenticateShutdownServers, NULL, 1.0, 1);
}

int
authenticateUnregister(const char *url, void *data)
{
    authenticator_t *authenticate = NULL;
    authenticateStateData *r = NULL;
    struct authenticateQueueData *rq = NULL;
    int k;
    int n = 0;
    if (Config.Program.authenticate == NULL)
	return 0;
    debug(29, 3) ("authenticateUnregister: '%s'\n", url);
    for (k = 0; k < NAuthenticators; k++) {
	authenticate = *(authenticate_child_table + k);
	if ((r = authenticate->authenticateState) == NULL)
	    continue;
	if (r->data != data)
	    continue;
	debug(29, 3) ("authenticateUnregister: Found match\n");
	r->handler = NULL;
	n++;
    }
    for (rq = authenticateQueueHead; rq; rq = rq->next) {
	if ((r = rq->authenticateState) == NULL)
	    continue;
	if (r->data != data)
	    continue;
	debug(29, 3) ("authenticateUnregister: Found match.\n");
	r->handler = NULL;
	n++;
    }
    debug(29, 3) ("authenticateUnregister: Unregistered %d handlers\n", n);
    return n;
}

void
authenticateStats(StoreEntry * sentry)
{
    int k;
    storeAppendPrintf(sentry, "Authenticator Statistics:\n");
    storeAppendPrintf(sentry, "requests: %d\n",
	AuthenticateStats.requests);
    storeAppendPrintf(sentry, "replies: %d\n",
	AuthenticateStats.replies);
    storeAppendPrintf(sentry, "queue length: %d\n",
	AuthenticateStats.queue_size);
    storeAppendPrintf(sentry, "avg service time: %d msec\n",
	AuthenticateStats.avg_svc_time);
    storeAppendPrintf(sentry, "number of authenticators: %d\n",
	NAuthenticators);
    storeAppendPrintf(sentry, "use histogram:\n");
    for (k = 0; k < NAuthenticators; k++) {
	storeAppendPrintf(sentry, "    authenticator #%d: %d (%d requests)\n",
	    k + 1,
	    AuthenticateStats.use_hist[k],
	    AuthenticateStats.rewrites[k]);
    }
}
