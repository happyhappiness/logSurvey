
    if (friends->edges_head == NULL)
	return 0;
    if (theOutIcpConnection < 0) {
	debug(15, 0, "neighborsUdpPing: There is no ICP socket!\n");
	debug(15, 0, "Cannot query neighbors for '%s'.\n", url);
	debug(15, 0, "Check 'icp_port' in your config file\n");
	fatal_dump(NULL);
    }
    for (i = 0, e = friends->first_ping; i++ < friends->n; e = e->next) {
	if (entry->swap_status != NO_SWAP)
	    fatal_dump("neighborsUdpPing: bad swap_status");
