    dnsserver_t *dnsData = NULL;
    char *name = inet_ntoa(addr);

    assert(handler);

    debug(35, 4) ("fqdncache_nbgethostbyaddr: Name '%s'.\n", name);
    FqdncacheStats.requests++;
