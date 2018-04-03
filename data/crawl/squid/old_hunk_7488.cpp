{
    ipcache_entry *i = NULL;
    dnsserver_t *dnsData = NULL;
    struct hostent *hp = NULL;

    if (!handler)
	fatal_dump("ipcache_nbgethostbyname: NULL handler");
