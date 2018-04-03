netdbSaveState(void *foo)
{
    LOCAL_ARRAY(char, path, SQUID_MAXPATHLEN);
    Logfile *lf;
    netdbEntry *n;
    net_db_name *x;
    struct timeval start = current_time;
    int count = 0;
    snprintf(path, SQUID_MAXPATHLEN, "%s/netdb_state", storeSwapDir(0));
    /*
     * This was nicer when we were using stdio, but thanks to
     * Solaris bugs, its a bad idea.  fopen can fail if more than
     * 256 FDs are open.
     */
    lf = logfileOpen(path, 4096, 0);
    if (NULL == lf) {
	debug(50, 1) ("netdbSaveState: %s: %s\n", path, xstrerror());
	return;
    }
    hash_first(addr_table);
    while ((n = (netdbEntry *) hash_next(addr_table))) {
	if (n->pings_recv == 0)
	    continue;
	logfilePrintf(lf, "%s %d %d %10.5f %10.5f %d %d",
	    n->network,
	    n->pings_sent,
	    n->pings_recv,
