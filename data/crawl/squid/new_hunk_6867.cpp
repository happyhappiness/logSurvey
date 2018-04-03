    int list_count = 0;
    int removed = 0;
    list = xcalloc(meta_data.netdb_addrs, sizeof(netdbEntry *));
    n = (netdbEntry *) hash_first(addr_table);
    while (n != NULL) {
	assert(list_count < meta_data.netdb_addrs);
	*(list + list_count) = n;
	list_count++;
        n = (netdbEntry *) hash_next(addr_table);
    }
    qsort((char *) list,
	list_count,
