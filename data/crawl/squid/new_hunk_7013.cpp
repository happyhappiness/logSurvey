{
    ipcache_entry *i = NULL;
    ipcache_addrs *addrs;

    if (!name)
	fatal_dump("ipcache_gethostbyname: NULL name");
