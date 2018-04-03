
    if (Config.onoff.redirector_bypass)
        storeAppendPrintf(sentry, "\nNumber of requests bypassed "
                          "because all redirectors were busy: %d\n", redirectorBypassed);
}

static void
storeIdStats(StoreEntry * sentry)
{
    if (storeIds == NULL) {
        storeAppendPrintf(sentry, "No StoreId helpers defined\n");
        return;
    }

    helperStats(sentry, storeIds, "StoreId helper Statistics");

    if (Config.onoff.store_id_bypass)
        storeAppendPrintf(sentry, "\nNumber of requests bypassed "
                          "because all StoreId helpers were busy: %d\n", storeIdBypassed);
}

static void
constructHelperQuery(const char *name, struct helper *hlp, HLPCB *replyHandler, ClientHttpRequest * http, HLPCB *handler, void *data)
{
    ConnStateData * conn = http->getConn();
    const char *fqdn;
    char buf[MAX_REDIRECTOR_REQUEST_STRLEN];
    int sz;
    http_status status;
    char claddr[MAX_IPSTRLEN];
    char myaddr[MAX_IPSTRLEN];

    /** TODO: create a standalone method to initialize
     * the cbdata\redirectStateData for all the helpers.
     */
    redirectStateData *r = cbdataAlloc(redirectStateData);
    r->orig_url = xstrdup(http->uri);
    if (conn != NULL)
        r->client_addr = conn->log_addr;
