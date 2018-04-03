    fqdncache_entry *f = NULL;
    const struct hostent *hp = NULL;
    unsigned int ip;

    if (!name)
	fatal_dump("fqdncache_gethostbyaddr: NULL name");
