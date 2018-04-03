netdbSaveState(void *foo)
{
    LOCAL_ARRAY(char, path, SQUID_MAXPATHLEN);
    FILE *fp;
    netdbEntry *n;
    net_db_name *x;
    struct timeval start = current_time;
    int count = 0;
    snprintf(path, SQUID_MAXPATHLEN, "%s/netdb_state", storeSwapDir(0));
    fp = fopen(path, "w");
    if (fp == NULL) {
	debug(50, 1) ("netdbSaveState: %s: %s\n", path, xstrerror());
	return;
    }
    hash_first(addr_table);
    while ((n = (netdbEntry *) hash_next(addr_table))) {
	if (n->pings_recv == 0)
	    continue;
	fprintf(fp, "%s %d %d %10.5f %10.5f %d %d",
	    n->network,
	    n->pings_sent,
	    n->pings_recv,
