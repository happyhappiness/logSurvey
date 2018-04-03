    char *name = inet_ntoa(addr);
    fqdncache_entry *f = NULL;
    struct in_addr ip;
    assert(name);
    FqdncacheStats.requests++;
    if ((f = fqdncache_get(name))) {
	if (fqdncacheExpiredEntry(f)) {
