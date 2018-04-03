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
peerSelectInit(void)
{
    memset(&PeerStats, '\0', sizeof(PeerStats));
}


void
peerHandleIcpReply(peer * p, neighbor_t type, icp_opcode_t op, void *data)
{
    psctrl_t *ctrl = data;
    int w_rtt;
    request_t *reqeust = ctrl->request;
    ctrl->pings->n_recv++;
    if (op == ICP_OP_MISS || op == ICP_OP_DECHO) {
	if (type == PEER_PARENT) {
	    w_rtt = tvSubMsec(ctrl->ping.start, current_time) / e->weight;
	    if (ctrl->ping.w_rtt == 0 || w_rtt < ctrl->ping.w_rtt) {
		ctrl->ping.best_parent = e;
		ctrl->ping.w_rtt = w_rtt;
	    }
	}
    } else if (op == ICP_OP_HIT || op == ICP_OP_HIT_OBJ) {
	hierarchyNote(request,
	    type == PEER_PARENT ? HIER_PARENT_HIT : HIER_SIBLING_HIT,
	    0,
	    p->host);
	peerSelectCallback(ctrl, p);
	return;
    } else if (op == ICP_OP_SECHO) {
	hierarchyNote(request,
	    HIER_SOURCE_FASTEST,
	    0,
	    request->host
	peerSelectCallback(ctrl, p);
	return;
    }
    if (ctrl->ping.n_recv < ping.n_replies_expected)
	return;
}