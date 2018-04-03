    dnsserver_t *dnsData = NULL;
    char *name = inet_ntoa(addr);

    if (!handler)
	fatal_dump("fqdncache_nbgethostbyaddr: NULL handler");

    debug(35, 4) ("fqdncache_nbgethostbyaddr: Name '%s'.\n", name);
    FqdncacheStats.requests++;
