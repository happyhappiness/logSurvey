    debug(44, 3, "peerSelect: direct = %d\n", direct);
    if (direct == DIRECT_YES) {
	debug(44, 3, "peerSelect: HIER_DIRECT\n");
	hierarchyNote(request, HIER_DIRECT, 0, request->host);
	protoStart(fd, entry, NULL, request);
	return;
    }
    if (peerSelectIcpPing(request, direct, entry)) {
	debug(44, 3, "peerSelect: Doing ICP pings\n");
	/* call neighborUdpPing and start timeout routine */
	if (neighborsUdpPing(request, entry)) {
	    entry->ping_status = PING_WAITING;
	    commSetSelect(fd,
		COMM_SELECT_TIMEOUT,
		peerPingTimeout,
		(void *) ctrl,
		Config.neighborTimeout);
	    return;
	}
	debug_trap("peerSelect: neighborsUdpPing returned 0");
    }
    if ((p = peerGetSomeParent(request, &code))) {
	debug(44, 3, "peerSelect: Got some parent %s/%s\n",
	    hier_strings[code], p->host);
	hierarchyNote(request, code, 0, p->host);
	protoStart(fd, entry, p, request);
    }
}

void
peerPingTimeout(int fd, void *data)
{
    peer_ctrl_t *ctrl = data;
    StoreEntry *entry = ctrl->entry;
    debug(44, 3, "peerPingTimeout: '%s'\n", entry->url);
    PeerStats.timeouts++;
    ctrl->timeout = 1;
    peerSelect(ctrl);
}

void
peerSelectInit(void)
{
    memset(&PeerStats, '\0', sizeof(PeerStats));
}
