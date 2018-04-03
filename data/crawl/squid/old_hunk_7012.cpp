{
    char *name = inet_ntoa(addr);
    fqdncache_entry *f = NULL;
    const struct hostent *hp = NULL;
    struct in_addr ip;
    static char *static_name = NULL;

    if (!name)
	fatal_dump("fqdncache_gethostbyaddr: NULL name");
