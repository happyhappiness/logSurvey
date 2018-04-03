    return n;
}

struct hostent *
ipcache_gethostbyname(char *name, int flags)
{
    ipcache_entry *i = NULL;
    struct hostent *hp = NULL;

    if (!name)
	fatal_dump("ipcache_gethostbyname: NULL name");
