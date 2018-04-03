    return n;
}

const ipcache_addrs *
ipcache_gethostbyname(const char *name, int flags)
{
    ipcache_entry *i = NULL;
    ipcache_addrs *addrs;
    const struct hostent *hp;

    if (!name)
	fatal_dump("ipcache_gethostbyname: NULL name");
