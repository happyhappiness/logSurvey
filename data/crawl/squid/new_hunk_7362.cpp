    fqdncache_entry *f = NULL;
    const struct hostent *hp = NULL;
    unsigned int ip;
    static char *static_name = NULL;

    if (!name)
	fatal_dump("fqdncache_gethostbyaddr: NULL name");
