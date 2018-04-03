{
    ipcache_entry *i = NULL;
    dnsserver_t *dnsData = NULL;
    const ipcache_addrs *addrs = NULL;

    if (!handler)
	fatal_dump("ipcache_nbgethostbyname: NULL handler");
