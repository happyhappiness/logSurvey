    }
    if (entry->swap_status != NO_SWAP)
	fatal_dump("neighborsUdpPing: bad swap_status");

    for (i = 0, e = Peers.first_ping; i++ < Peers.n; e = e->next) {
	if (e == NULL)
	    e = Peers.peers_head;
