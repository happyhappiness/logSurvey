    RH *handler;
} authenticateStateData;

static HLPCB authenticateHandleReply;
static void authenticateStateFree(authenticateStateData * r);
static helper *authenticators = NULL;

static void
authenticateHandleReply(void *data, char *reply)
{
    authenticateStateData *r = data;
    int valid;
    char *t = NULL;
    debug(29, 5) ("authenticateHandleReply: {%s}\n", reply);
    if ((t = strchr(reply, ' ')))
	*t = '\0';
    if (*reply == '\0')
	reply = NULL;
    valid = cbdataValid(r->data);
    cbdataUnlock(r->data);
    if (valid)
	r->handler(r->data, reply);
    authenticateStateFree(r);
}

static void
authenticateStateFree(authenticateStateData * r)
{
    cbdataFree(r);
}

static void
authenticateStats(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "Authenticator Statistics:\n");
    helperStats(sentry, authenticators);
}

/**** PUBLIC FUNCTIONS ****/


void
authenticateStart(acl_proxy_auth_user * auth_user, RH * handler, void *data)
{
    authenticateStateData *r = NULL;
    char buf[8192];
    assert(auth_user);
    assert(handler);
    debug(29, 5) ("authenticateStart: '%s:%s'\n", auth_user->user,
	auth_user->passwd);
    if (Config.Program.authenticate == NULL) {
	handler(data, NULL);
	return;
    }
    r = xcalloc(1, sizeof(authenticateStateData));
    cbdataAdd(r, MEM_NONE);
    r->handler = handler;
    r->data = data;
    r->auth_user = auth_user;
    snprintf(buf, 8192, "%s %s\n", r->auth_user->user, r->auth_user->passwd);
    helperSubmit(authenticators, buf, authenticateHandleReply, r);
}

void
authenticateInit(void)
{
    static int init = 0;
    safe_free(authenticators);
    if (!Config.Program.authenticate)
	return;
    authenticators = xcalloc(1, sizeof(*authenticators));
    authenticators->id_name = "authenticator";
    authenticators->cmdline = Config.Program.authenticate;
    authenticators->n_to_start = Config.authenticateChildren;
    authenticators->ipc_type = IPC_TCP_SOCKET;
    helperOpenServers(authenticators);
    if (!init) {
	cachemgrRegister("authenticator",
	    "User Authenticator Stats",
	    authenticateStats, 0, 1);
    }
    init++;
}

void
authenticateShutdown(void)
{
    if (authenticators)
	helperShutdown(authenticators);
}
