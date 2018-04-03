
    memset(line, '\0', SM_PAGE_SIZE);

    storeAppend(sentry, open_bracket, (int) strlen(open_bracket));

    sprintf(line, "{Squid Object Cache: Version %s}\n", version_string);
    storeAppend(sentry, line, strlen(line));

    tod = mkrfc850(&squid_starttime);

    sprintf(line, "{Start Time:\t%s}\n", tod);
    storeAppend(sentry, line, strlen(line));

    tod = mkrfc850(&squid_curtime);
    sprintf(line, "{Current Time:\t%s}\n", tod);
    storeAppend(sentry, line, strlen(line));

    /* -------------------------------------------------- */

    sprintf(line, "{Connection information for %s:}\n", appname);
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\tNumber of connections:\t%lu}\n", nconn);
    storeAppend(sentry, line, strlen(line));

    {
	float f;
	f = squid_curtime - squid_starttime;
	sprintf(line, "{\tConnections per hour:\t%.1f}\n", f == 0.0 ? 0.0 :
	    (nconn / (f / 3600)));
	storeAppend(sentry, line, strlen(line));
    }

    /* -------------------------------------------------- */



    sprintf(line, "{Cache information for %s:}\n", appname);
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\tStorage Swap size:\t%d MB}\n", storeGetSwapSize() >> 10);
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\tStorage Mem size:\t%d KB}\n", storeGetMemSize() >> 10);
    storeAppend(sentry, line, strlen(line));

    tod = mkrfc850(&next_cleaning);
    sprintf(line, "{\tStorage Expiration at:\t%s}\n", tod);
    storeAppend(sentry, line, strlen(line));

#if defined(HAVE_GETRUSAGE) && defined(RUSAGE_SELF)
    sprintf(line, "{Resource usage for %s:}\n", appname);
    storeAppend(sentry, line, strlen(line));

    getrusage(RUSAGE_SELF, &rusage);
    sprintf(line, "{\tCPU Usage: user %d sys %d}\n{\tProcess Size: rss %d KB}\n",
	rusage.ru_utime.tv_sec, rusage.ru_stime.tv_sec,
	rusage.ru_maxrss * getpagesize() >> 10);
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\tPage faults with physical i/o:\t%d}\n",
	rusage.ru_majflt);
    storeAppend(sentry, line, strlen(line));

#endif

#if HAVE_MALLINFO
    mp = mallinfo();

    sprintf(line, "{Memory usage for %s via mallinfo():}\n", appname);
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\ttotal space in arena:\t%d KB}\n", mp.arena >> 10);
    storeAppend(sentry, line, strlen(line));
    sprintf(line, "{\tnumber of ordinary blocks:\t%d}\n", mp.ordblks);
    storeAppend(sentry, line, strlen(line));
    sprintf(line, "{\tnumber of small blocks:\t%d}\n", mp.smblks);
    storeAppend(sentry, line, strlen(line));
    if (mp.hblks) {
	sprintf(line, "{\tnumber of holding blocks:\t%d}\n", mp.hblks);
	storeAppend(sentry, line, strlen(line));
    }
    if (mp.hblkhd) {
	sprintf(line, "{\tspace in holding block headers:\t%d}\n", mp.hblkhd);
	storeAppend(sentry, line, strlen(line));
    }
    if (mp.usmblks) {
	sprintf(line, "{\tspace in small blocks in use:\t%d}\n", mp.usmblks);
	storeAppend(sentry, line, strlen(line));
    }
    if (mp.fsmblks) {
	sprintf(line, "{\tspace in free blocks:\t%d}\n", mp.fsmblks);
	storeAppend(sentry, line, strlen(line));
    }
    sprintf(line, "{\tspace in ordinary blocks in use:\t%d KB}\n",
	mp.uordblks >> 10);
    storeAppend(sentry, line, strlen(line));
    sprintf(line, "{\tspace in free ordinary blocks:\t%d KB}\n", mp.fordblks >> 10);
    storeAppend(sentry, line, strlen(line));
    if (mp.keepcost) {
	sprintf(line, "{\tcost of enabling keep option:\t%d}\n", mp.keepcost);
	storeAppend(sentry, line, strlen(line));
    }
#if HAVE_EXT_MALLINFO
    sprintf(line, "{\tmax size of small blocks:\t%d}\n", mp.mxfast);
    storeAppend(sentry, line, strlen(line));
    sprintf(line, "{\tnumber of small blocks in a holding block:\t%d}\n",
	mp.nlblks);
    storeAppend(sentry, line, strlen(line));
    sprintf(line, "{\tsmall block rounding factor:\t%d}\n", mp.grain);
    storeAppend(sentry, line, strlen(line));
    sprintf(line, "{\tspace (including overhead) allocated in ord. blks:\t%d}\n"
	,mp.uordbytes);
    sprintf(line, "{\tnumber of ordinary blocks allocated:\t%d}\n",
	mp.allocated);
    storeAppend(sentry, line, strlen(line));
    sprintf(line, "{\tbytes used in maintaining the free tree:\t%d}\n",
	mp.treeoverhead);
    storeAppend(sentry, line, strlen(line));

#endif /* HAVE_EXT_MALLINFO */

#endif /* HAVE_MALLINFO */

    sprintf(line, "{File descriptor usage for %s:}\n", appname);
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\tMax number of file desc available:\t%d}\n", getMaxFD());
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\tLargest file desc currently in use:\t%d}\n",
	fdstat_biggest_fd());
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\tAvailable number of file descriptors :\t%d}\n",
	fdstat_are_n_free_fd(0));
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\tReserved number of file descriptors :\t%d}\n",
	RESERVED_FD);
    storeAppend(sentry, line, strlen(line));

    {
	int i, max_fd = getMaxFD();
	char *s = NULL;

	sprintf(line, "{\tActive file descriptors:}\n");
	storeAppend(sentry, line, strlen(line));

	for (i = 0; i < max_fd; i++) {
	    int lft, to;
