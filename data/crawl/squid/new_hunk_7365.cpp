
void
peerSelect(request_t * request,
    StoreEntry * entry,
    PSC callback,
    PSC fail_callback,
    void *callback_data)
{
    ps_state *psstate = xcalloc(1, sizeof(ps_state));
    psstate->request = requestLink(request);
    psstate->entry = entry;
    psstate->callback = callback;
    psstate->fail_callback = fail_callback;
    psstate->callback_data = callback_data;
    psstate->icp.start = current_time;
    peerSelectFoo(psstate);
}

static void
peerCheckNeverDirectDone(int answer, void *data)
{
    ps_state *psstate = data;
    debug(44, 3, "peerCheckNeverDirectDone: %d\n", answer);
    psstate->never_direct = answer ? 1 : -1;
    peerSelectFoo(psstate);
}

static void
peerCheckAlwaysDirectDone(int answer, void *data)
{
    ps_state *psstate = data;
    debug(44, 3, "peerCheckAlwaysDirectDone: %d\n", answer);
    psstate->always_direct = answer ? 1 : -1;
    peerSelectFoo(psstate);
}

static void
peerSelectCallback(ps_state * psstate, peer * p)
{
    StoreEntry *entry = psstate->entry;
    if (entry) {
	if (entry->ping_status == PING_WAITING)
	    eventDelete(peerPingTimeout, psstate);
	entry->ping_status = PING_DONE;
    }
    psstate->callback(p, psstate->callback_data);
    requestUnlink(psstate->request);
    xfree(psstate);
}

static void
peerSelectCallbackFail(ps_state * psstate)
{
    request_t *request = psstate->request;
    char *url = psstate->entry ? psstate->entry->url : urlCanonical(request, NULL);
    debug(44, 1, "Failed to select source for '%s'\n", url);
    debug(44, 1, "  always_direct = %d\n", psstate->always_direct);
    debug(44, 1, "   never_direct = %d\n", psstate->never_direct);
    debug(44, 1, "        timeout = %d\n", psstate->icp.timeout);
    psstate->fail_callback(NULL, psstate->callback_data);
    requestUnlink(psstate->request);
    xfree(psstate);
}

static void
peerSelectFoo(ps_state * psstate)
{
    peer *p;
    hier_code code;
    StoreEntry *entry = psstate->entry;
    request_t *request = psstate->request;
    int direct;
    debug(44, 3, "peerSelect: '%s %s'\n",
	RequestMethodStr[request->method],
	request->host);
    if (psstate->never_direct == 0) {
	aclNBCheck(Config.accessList.NeverDirect,
	    request,
	    request->client_addr,
	    NULL,		/* user agent */
	    NULL,		/* ident */
	    peerCheckNeverDirectDone,
	    psstate);
	return;
    } else if (psstate->never_direct > 0) {
	direct = DIRECT_NO;
    } else if (psstate->always_direct == 0) {
	aclNBCheck(Config.accessList.AlwaysDirect,
	    request,
	    request->client_addr,
	    NULL,		/* user agent */
	    NULL,		/* ident */
	    peerCheckAlwaysDirectDone,
	    psstate);
	return;
    } else if (psstate->always_direct > 0) {
	direct = DIRECT_YES;
    } else {
	direct = DIRECT_MAYBE;
    }
    debug(44, 3, "peerSelect: direct = %d\n", direct);
    if (direct == DIRECT_YES) {
	debug(44, 3, "peerSelect: HIER_DIRECT\n");
	hierarchyNote(request, HIER_DIRECT, &psstate->icp, request->host);
	peerSelectCallback(psstate, NULL);
	return;
    }
    if (peerSelectIcpPing(request, direct, entry)) {
	if (entry->ping_status != PING_NONE)
	    fatal_dump("peerSelectFoo: bad ping_status");
	debug(44, 3, "peerSelect: Doing ICP pings\n");
	psstate->icp.n_sent = neighborsUdpPing(request,
	    entry,
	    peerHandleIcpReply,
	    psstate,
	    &psstate->icp.n_replies_expected);
	if (psstate->icp.n_sent > 0) {
	    entry->ping_status = PING_WAITING;
	    eventAdd("peerPingTimeout",
		peerPingTimeout,
		psstate,
		Config.neighborTimeout);
	    return;
	}
	debug_trap("peerSelect: neighborsUdpPing returned 0");
    }
    if ((p = psstate->best_parent)) {
	code = HIER_BEST_PARENT_MISS;
	debug(44, 3, "peerSelect: %s/%s\n", hier_strings[code], p->host);
	hierarchyNote(request, code, &psstate->icp, p->host);
	peerSelectCallback(psstate, p);
    } else if (direct != DIRECT_NO) {
	code = HIER_DIRECT;
	debug(44, 3, "peerSelect: %s/%s\n", hier_strings[code], request->host);
	hierarchyNote(request, code, &psstate->icp, request->host);
	peerSelectCallback(psstate, NULL);
    } else if ((p = peerGetSomeParent(request, &code))) {
	debug(44, 3, "peerSelect: %s/%s\n", hier_strings[code], p->host);
	hierarchyNote(request, code, &psstate->icp, p->host);
	peerSelectCallback(psstate, p);
    } else {
	code = HIER_NO_DIRECT_FAIL;
	hierarchyNote(request, code, &psstate->icp, NULL);
	peerSelectCallbackFail(psstate);
    }
}

void
peerPingTimeout(void *data)
{
    ps_state *psstate = data;
    StoreEntry *entry = psstate->entry;
    debug(44, 3, "peerPingTimeout: '%s'\n", entry->url);
    entry->ping_status = PING_TIMEOUT;
    PeerStats.timeouts++;
    psstate->icp.timeout = 1;
    peerSelectFoo(psstate);
}

void
