    }
    if (entry->swap_status != NO_SWAP)
	fatal_dump("neighborsUdpPing: bad swap_status");
    for (i = 0, e = Peers.first_ping; i++ < Peers.n; e = e->next) {
	if (e == NULL)
	    e = Peers.peers_head;
	debug(15, 5, "neighborsUdpPing: Peer %s\n", e->host);

	/* skip any cache where we failed to connect() w/in the last 60s */
	if (squid_curtime - e->last_fail_time < 60)
	    continue;

	if (!peerWouldBePinged(e, request))
	    continue;		/* next peer */
	if (e->options & NEIGHBOR_NO_QUERY)
	    continue;
	/* the case below seems strange, but can happen if the
	 * URL host is on the other side of a firewall */
	if (e->type == PEER_SIBLING)
	    if (!BIT_TEST(request->flags, REQ_HIERARCHICAL))
		continue;

