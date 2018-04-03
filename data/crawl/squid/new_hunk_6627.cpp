	return;
    }
    if (peerSelectIcpPing(request, direct, entry)) {
	assert(entry->ping_status == PING_NONE);
	debug(44, 3) ("peerSelect: Doing ICP pings\n");
	psstate->icp.n_sent = neighborsUdpPing(request,
	    entry,
	    peerHandleIcpReply,
	    psstate,
	    &psstate->icp.n_replies_expected);
	if (psstate->icp.n_sent == 0)
	    debug(44, 0) ("WARNING: neighborsUdpPing returned 0\n");
	if (psstate->icp.n_replies_expected > 0) {
	    entry->ping_status = PING_WAITING;
	    eventAdd("peerPingTimeout",
		peerPingTimeout,
		psstate,
		Config.neighborTimeout);
	    return;
	}
    }
    debug(44, 3) ("peerSelectFoo: After peerSelectIcpPing.\n");
    if (peerCheckNetdbDirect(psstate)) {