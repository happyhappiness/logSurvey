    return n;
}

ipcache_addrs *
ipcache_gethostbyname(char *name, int flags)
{
    ipcache_entry *i = NULL;
    ipcache_addrs *addrs;
    struct hostent *hp;

    if (!name)
	fatal_dump("ipcache_gethostbyname: NULL name");
