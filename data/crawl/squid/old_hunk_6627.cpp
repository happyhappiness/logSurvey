	return;
    }
    if (peerSelectIcpPing(request, direct, entry)) {
	if (entry->ping_status != PING_NONE)
	    fatal_dump("peerSelectFoo: bad ping_status");
	debug(44, 3) ("peerSelect: Doing ICP pings\n");
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
    debug(44, 3) ("peerSelectFoo: After peerSelectIcpPing.\n");
    if (peerCheckNetdbDirect(psstate)) {