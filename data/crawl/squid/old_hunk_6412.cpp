    if (theInIcpConnection < 0)
	fatal("Cannot open ICP Port");
    commSetSelect(theInIcpConnection,
	COMM_SELECT_READ,
	icpHandleUdp,
	NULL, 0);
    for (s = Config.mcast_group_list; s; s = s->next)
	ipcache_nbgethostbyname(s->key, mcastJoinGroups, NULL);
    debug(12, 1) ("Accepting ICP messages on port %d, FD %d.\n",
