    int k = 0;
    int list_count = 0;
    int removed = 0;
    list = xcalloc(meta_data.netdb_addrs, sizeof(netdbEntry *));
    for (n = netdbGetFirst(addr_table); n; n = netdbGetNext(addr_table)) {
	*(list + list_count) = n;
	list_count++;
	if (list_count > meta_data.netdb_addrs)
	    fatal_dump("netdbPurgeLRU: list_count overflow");
    }
    qsort((char *) list,
	list_count,
	sizeof(netdbEntry *),
	(QS) netdbLRU);
    for (k = 0; k < list_count; k++) {
	if (meta_data.netdb_addrs < NETDB_LOW_MARK)
	    break;
	netdbRelease(*(list + k));
	removed++;
