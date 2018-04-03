	fatal_dump(NULL);
    }
    if (entry->swap_status != NO_SWAP)
        fatal_dump("neighborsUdpPing: bad swap_status");
    for (i = 0, e = friends.first_ping; i++ < friends.n; e = e->next) {
	if (e == NULL)
	    e = friends.edges_head;