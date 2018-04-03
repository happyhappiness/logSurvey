
    if (friends->edges_head == NULL)
	return 0;

    for (i = 0, e = friends->first_ping; i++ < friends->n; e = e->next) {
	if (entry->swap_status != NO_SWAP)
	    fatal_dump("neighborsUdpPing: bad swap_status");
