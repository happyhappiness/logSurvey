    RH *handler;
} redirectStateData;

typedef struct _redirector {
    int index;
    helper_flags flags;
    int fd;
    char *inbuf;
    unsigned int size;
    unsigned int offset;
    struct timeval dispatch_time;
    redirectStateData *redirectState;
    dlink_node link;
} redirector_t;

static struct {
    int requests;
    int replies;
    int errors;
    int avg_svc_time;
    int queue_size;
    int use_hist[DefaultRedirectChildrenMax];
    int rewrites[DefaultRedirectChildrenMax];
} RedirectStats;

struct redirectQueueData {
    struct redirectQueueData *next;
    redirectStateData *redirectState;
};

static redirector_t *GetFirstAvailable(void);
static PF redirectHandleRead;
static redirectStateData *Dequeue(void);
static void Enqueue(redirectStateData *);
static void redirectDispatch(redirector_t *, redirectStateData *);
static void redirectStateFree(redirectStateData * r);
static PF redirectorStateFree;

static dlink_list redirectors;
static int NRedirectors = 0;
static int NRedirectorsOpen = 0;
static struct redirectQueueData *redirectQueueHead = NULL;
static struct redirectQueueData **redirectQueueTailP = &redirectQueueHead;

static void
redirectHandleRead(int fd, void *data)
{
    redirector_t *redirector = data;
    int len;
    redirectStateData *r = redirector->redirectState;
    char *t = NULL;
    int n;
    int valid;
    assert(cbdataValid(data));
    Counter.syscalls.sock.reads++;
    len = read(fd,
	redirector->inbuf + redirector->offset,
	redirector->size - redirector->offset);
    fd_bytes(fd, len, FD_READ);
    debug(29, 5) ("redirectHandleRead: %d bytes from Redirector #%d.\n",
	len, redirector->index + 1);
    if (len <= 0) {
	if (len < 0)
	    debug(50, 1) ("redirectHandleRead: FD %d read: %s\n", fd, xstrerror());
	debug(29, redirector->flags.closing ? 5 : 1)
	    ("FD %d: Connection from Redirector #%d is closed, disabling\n",
	    fd, redirector->index + 1);
	redirector->flags.alive = 0;
	redirector->flags.busy = 0;
	redirector->flags.closing = 0;
	redirector->flags.shutdown = 0;
	memFree(MEM_8K_BUF, redirector->inbuf);
	redirector->inbuf = NULL;
	comm_close(fd);
	return;
    }
    if (len != 1)
	RedirectStats.rewrites[redirector->index]++;
    redirector->offset += len;
    redirector->inbuf[redirector->offset] = '\0';
    if ((t = strchr(redirector->inbuf, '\n'))) {
	/* end of record found */
	*t = '\0';
	if ((t = strchr(redirector->inbuf, ' ')))
	    *t = '\0';		/* terminate at space */
	if (r == NULL) {
	    /* A naughty redirector has spoken without being spoken to */
	    /* B.R.Foster@massey.ac.nz, SQUID/1.1.3 */
	    debug(29, 0) ("redirectHandleRead: unexpected reply: '%s'\n",
		redirector->inbuf);
	    redirector->offset = 0;
	} else {
	    debug(29, 5) ("redirectHandleRead: reply: '%s'\n",
		redirector->inbuf);
	    valid = cbdataValid(r->data);
	    cbdataUnlock(r->data);
	    if (valid)
		r->handler(r->data,
		    t == redirector->inbuf ? NULL : redirector->inbuf);
	    redirectStateFree(r);
	    redirector->redirectState = NULL;
	    redirector->flags.busy = 0;
	    redirector->offset = 0;
	    n = ++RedirectStats.replies;
	    RedirectStats.avg_svc_time =
		intAverage(RedirectStats.avg_svc_time,
		tvSubMsec(redirector->dispatch_time, current_time),
		n, REDIRECT_AV_FACTOR);
	    if (redirector->flags.shutdown)
		comm_close(redirector->fd);
	}
    } else {
	commSetSelect(redirector->fd,
	    COMM_SELECT_READ,
	    redirectHandleRead,
	    redirector, 0);
    }
    while ((redirector = GetFirstAvailable()) && (r = Dequeue()))
	redirectDispatch(redirector, r);
}

static void
Enqueue(redirectStateData * r)
{
    struct redirectQueueData *new = xcalloc(1, sizeof(struct redirectQueueData));
    new->redirectState = r;
    *redirectQueueTailP = new;
    redirectQueueTailP = &new->next;
    RedirectStats.queue_size++;
}

static redirectStateData *
Dequeue(void)
{
    struct redirectQueueData *old = NULL;
    redirectStateData *r = NULL;
    if (redirectQueueHead) {
	r = redirectQueueHead->redirectState;
	old = redirectQueueHead;
	redirectQueueHead = redirectQueueHead->next;
	if (redirectQueueHead == NULL)
	    redirectQueueTailP = &redirectQueueHead;
	safe_free(old);
	RedirectStats.queue_size--;
    }
    return r;
}

static redirector_t *
GetFirstAvailable(void)
{
    dlink_node *n;
    redirector_t *r = NULL;
    for (n = redirectors.head; n != NULL; n = n->next) {
	r = n->data;
	if (r->flags.busy)
	    continue;
	if (!r->flags.alive)
	    continue;
	return r;
    }
    return NULL;
}

static void
redirectStateFree(redirectStateData * r)
{
    safe_free(r->orig_url);
    safe_free(r);
}


static void
redirectDispatch(redirector_t * redirect, redirectStateData * r)
{
    char *buf = NULL;
    const char *fqdn = NULL;
    int len;
    if (r->handler == NULL) {
	debug(29, 1) ("redirectDispatch: skipping '%s' because no handler\n",
	    r->orig_url);
	redirectStateFree(r);
	return;
    }
    redirect->flags.busy = 1;
    redirect->redirectState = r;
    redirect->dispatch_time = current_time;
    if ((fqdn = fqdncache_gethostbyaddr(r->client_addr, 0)) == NULL)
	fqdn = dash_str;
    buf = memAllocate(MEM_8K_BUF);
    snprintf(buf, 8192, "%s %s/%s %s %s\n",
	r->orig_url,
	inet_ntoa(r->client_addr),
	fqdn,
	r->client_ident,
	r->method_s);
    len = strlen(buf);
    comm_write(redirect->fd,
	buf,
	len,
	NULL,			/* Handler */
	NULL,			/* Handler-data */
	memFree8K);
    commSetSelect(redirect->fd,
	COMM_SELECT_READ,
	redirectHandleRead,
	redirect, 0);
    debug(29, 5) ("redirectDispatch: Request sent to Redirector #%d, %d bytes\n",
	redirect->index + 1, len);
    RedirectStats.use_hist[redirect->index]++;
    RedirectStats.requests++;
}


/**** PUBLIC FUNCTIONS ****/


void
redirectStart(clientHttpRequest * http, RH * handler, void *data)
{
    ConnStateData *conn = http->conn;
    redirectStateData *r = NULL;
    redirector_t *redirector = NULL;
    if (!http)
	fatal_dump("redirectStart: NULL clientHttpRequest");
    if (!handler)
	fatal_dump("redirectStart: NULL handler");
    debug(29, 5) ("redirectStart: '%s'\n", http->uri);
    if (Config.Program.redirect == NULL) {
	handler(data, NULL);
	return;
    }
    r = xcalloc(1, sizeof(redirectStateData));
    r->orig_url = xstrdup(http->uri);
    r->client_addr = conn->log_addr;
    if (conn->ident.ident == NULL || *conn->ident.ident == '\0') {
