    RH *handler;
} redirectStateData;

static HLPCB redirectHandleReply;
static void redirectStateFree(redirectStateData * r);
static helper *redirectors = NULL;
static OBJH redirectStats;

static void
redirectHandleReply(void *data, char *reply)
{
    redirectStateData *r = data;
    int valid;
    char *t;
    assert(cbdataValid(data));
    debug(29, 5) ("redirectHandleRead: {%s}\n", reply);
    if ((t = strchr(reply, ' ')))
	t = '\0';
    if (*reply == '\0')
	reply = NULL;
    valid = cbdataValid(r->data);
    cbdataUnlock(r->data);
    if (valid)
	r->handler(r->data, reply);
    redirectStateFree(r);
}

static void
redirectStateFree(redirectStateData * r)
{
    safe_free(r->orig_url);
    cbdataFree(r);
}

static void
redirectStats(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "Redirector Statistics:\n");
    helperStats(sentry, redirectors);
}

/**** PUBLIC FUNCTIONS ****/

void
redirectStart(clientHttpRequest * http, RH * handler, void *data)
{
    ConnStateData *conn = http->conn;
    redirectStateData *r = NULL;
    const char *fqdn;
    char buf[8192];
    assert(http);
    assert(handler);
    debug(29, 5) ("redirectStart: '%s'\n", http->uri);
    if (Config.Program.redirect == NULL) {
	handler(data, NULL);
	return;
    }
    r = xcalloc(1, sizeof(redirectStateData));
    cbdataAdd(r, MEM_NONE);
    r->orig_url = xstrdup(http->uri);
    r->client_addr = conn->log_addr;
    if (conn->ident.ident == NULL || *conn->ident.ident == '\0') {
