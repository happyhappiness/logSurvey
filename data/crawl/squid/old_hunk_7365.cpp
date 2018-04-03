
void
peerSelect(request_t * request,
	StoreEntry *entry,
	PSC callback,
	PSC fail_callback,
	void *callback_data)
{
    psctrl_t *ctrl = xcalloc(1, sizeof(psctrl_t));
    ctrl->request = requestLink(request);
    ctrl->entry = entry;
    ctrl->callback = callback;
    ctrl->fail_callback = fail_callback;
    ctrl->callback_data = callback_data;
    peerSelectFoo(ctrl);
}

static void
peerCheckNeverDirectDone(int answer, void *data)
{
    psctrl_t *ctrl = data;
    debug(44, 3, "peerCheckNeverDirectDone: %d\n", answer);
    ctrl->never_direct = answer ? 1 : -1;
    peerSelectFoo(ctrl);
}

static void
peerCheckAlwaysDirectDone(int answer, void *data)
{
    psctrl_t *ctrl = data;
    debug(44, 3, "peerCheckAlwaysDirectDone: %d\n", answer);
    ctrl->always_direct = answer ? 1 : -1;
    peerSelectFoo(ctrl);
}

static void
peerSelectCallback(psctrl_t * ctrl, peer * p)
{
    if (!ctrl->ping.timeout)
	eventDelete(peerPingTimeout, ctrl);
    ctrl->callback(p, ctrl->callback_data);
    requestUnlink(ctrl->request);
    xfree(ctrl);
}

static void
peerSelectCallbackFail(psctrl_t * ctrl)
{
    request_t *request = ctrl->request;
    char *url = ctrl->entry ? ctrl->entry->url : urlCanonical(request, NULL);
    debug(44, 1, "Failed to select source for '%s'\n", url);
    debug(44, 1, "  always_direct = %d\n", ctrl->always_direct);
    debug(44, 1, "   never_direct = %d\n", ctrl->never_direct);
    debug(44, 1, "        timeout = %d\n", ctrl->ping.timeout);
    ctrl->fail_callback(NULL, ctrl->callback_data);
    requestUnlink(ctrl->request);
    xfree(ctrl);
}

static void
peerSelectFoo(psctrl_t * ctrl)
{
    peer *p;
    hier_code code;
    StoreEntry *entry = ctrl->entry;
    request_t *request = ctrl->request;
    int direct;
    debug(44, 3, "peerSelect: '%s'\n", entry->url);
    if (ctrl->never_direct == 0) {
	aclNBCheck(Config.accessList.NeverDirect,
	    request,
	    request->client_addr,
	    NULL,		/* user agent */
	    NULL,		/* ident */
	    peerCheckNeverDirectDone,
	    ctrl);
	return;
    } else if (ctrl->never_direct > 0) {
	direct = DIRECT_NO;
    } else if (ctrl->always_direct == 0) {
	aclNBCheck(Config.accessList.AlwaysDirect,
	    request,
	    request->client_addr,
	    NULL,		/* user agent */
	    NULL,		/* ident */
	    peerCheckAlwaysDirectDone,
	    ctrl);
	return;
    } else if (ctrl->always_direct > 0) {
	direct = DIRECT_YES;
    } else {
	direct = DIRECT_MAYBE;
    }
    debug(44, 3, "peerSelect: direct = %d\n", direct);
    if (direct == DIRECT_YES) {
	debug(44, 3, "peerSelect: HIER_DIRECT\n");
	hierarchyNote(request, HIER_DIRECT, ctrl->ping.timeout, request->host);
	peerSelectCallback(ctrl, NULL);
	return;
    }
    if (peerSelectIcpPing(request, direct, entry)) {
	if (entry->ping_status != PING_NONE)
		fatal_dump("peerSelectFoo: bad ping_status");
	debug(44, 3, "peerSelect: Doing ICP pings\n");
	ctrl->ping.n_sent = neighborsUdpPing(request,
		entry,
		&ctrl->ping.n_replies_expected);
	if (ctrl->ping.n_sent > 0) {
	    entry->ping_status = PING_WAITING;
	    eventAdd("peerPingTimeout",
		peerPingTimeout,
		ctrl,
		Config.neighborTimeout);
	    ctrl->ping.start = current_time;
	    return;
	}
	debug_trap("peerSelect: neighborsUdpPing returned 0");
    }
    if ((p = ctrl->ping.best_parent)) {
	code = HIER_BEST_PARENT_MISS;
	debug(44, 3, "peerSelect: %s/%s\n", hier_strings[code], p->host);
	hierarchyNote(request, code, ctrl->ping.timeout, p->host);
	peerSelectCallback(ctrl, p);
    } else if (direct != DIRECT_NO) {
	code = HIER_DIRECT;
	debug(44, 3, "peerSelect: %s/%s\n", hier_strings[code], request->host);
	hierarchyNote(request, code, ctrl->ping.timeout, request->host);
	peerSelectCallback(ctrl, NULL);
    } else if ((p = peerGetSomeParent(request, &code))) {
	debug(44, 3, "peerSelect: %s/%s\n", hier_strings[code], p->host);
	hierarchyNote(request, code, ctrl->ping.timeout, p->host);
	peerSelectCallback(ctrl, p);
    } else {
	code = HIER_NO_DIRECT_FAIL;
	hierarchyNote(request, code, ctrl->ping.timeout, NULL);
	peerSelectCallbackFail(ctrl);
    }
}

void
peerPingTimeout(void *data)
{
    psctrl_t *ctrl = data;
    StoreEntry *entry = ctrl->entry;
    debug(44, 3, "peerPingTimeout: '%s'\n", entry->url);
    entry->ping_status = PING_TIMEOUT;
    PeerStats.timeouts++;
    ctrl->ping.timeout = 1;
    peerSelectFoo(ctrl);
}

void
peerPingComplete(void *data)
{
    psctrl_t *ctrl = data;
    StoreEntry *entry = ctrl->entry;
    debug(44, 3, "peerPingComplete: '%s'\n", entry->url);
    entry->ping_status = PING_DONE;
    peerSelectFoo(ctrl);
}

void
