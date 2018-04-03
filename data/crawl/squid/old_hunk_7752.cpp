
    memset(line, '\0', SM_PAGE_SIZE);

    storeAppendPrintf(sentry, "{\n");

    storeAppendPrintf(sentry, "{Squid Object Cache: Version %s}\n", version_string);

    tod = mkrfc850(&squid_starttime);

    storeAppendPrintf(sentry, "{Start Time:\t%s}\n", tod);

    tod = mkrfc850(&squid_curtime);
    storeAppendPrintf(sentry, "{Current Time:\t%s}\n", tod);

    /* -------------------------------------------------- */

    storeAppendPrintf(sentry, "{Connection information for %s:}\n",
	appname);
    storeAppendPrintf(sentry, "{\tNumber of TCP connections:\t%lu}\n",
	ntcpconn);
    storeAppendPrintf(sentry, "{\tNumber of UDP connections:\t%lu}\n",
	nudpconn);

    {
	float f;
	f = squid_curtime - squid_starttime;
	storeAppendPrintf(sentry, "{\tConnections per hour:\t%.1f}\n",
	    f == 0.0 ? 0.0 :
	    ((ntcpconn + nudpconn) / (f / 3600)));
    }

    /* -------------------------------------------------- */

    storeAppendPrintf(sentry, "{Cache information for %s:}\n", appname);

    storeAppendPrintf(sentry, "{\tStorage Swap size:\t%d MB}\n", storeGetSwapSize() >> 10);

    storeAppendPrintf(sentry, "{\tStorage Mem size:\t%d KB}\n", storeGetMemSize() >> 10);

    tod = mkrfc850(&next_cleaning);
    storeAppendPrintf(sentry, "{\tStorage Expiration at:\t%s}\n", tod);

#if defined(HAVE_GETRUSAGE) && defined(RUSAGE_SELF)
    storeAppendPrintf(sentry, "{Resource usage for %s:}\n", appname);

    getrusage(RUSAGE_SELF, &rusage);
    storeAppendPrintf(sentry, "{\tCPU Usage: user %d sys %d}\n{\tProcess Size: rss %d KB}\n",
	rusage.ru_utime.tv_sec, rusage.ru_stime.tv_sec,
	rusage.ru_maxrss * getpagesize() >> 10);

    storeAppendPrintf(sentry, "{\tPage faults with physical i/o:\t%d}\n",
	rusage.ru_majflt);

#endif

#if HAVE_MALLINFO
    mp = mallinfo();

    storeAppendPrintf(sentry, "{Memory usage for %s via mallinfo():}\n", appname);

    storeAppendPrintf(sentry, "{\ttotal space in arena:\t%d KB}\n", mp.arena >> 10);
    storeAppendPrintf(sentry, "{\tnumber of ordinary blocks:\t%d}\n", mp.ordblks);
    storeAppendPrintf(sentry, "{\tnumber of small blocks:\t%d}\n", mp.smblks);
    if (mp.hblks) {
	storeAppendPrintf(sentry, "{\tnumber of holding blocks:\t%d}\n", mp.hblks);
    }
    if (mp.hblkhd) {
	storeAppendPrintf(sentry, "{\tspace in holding block headers:\t%d}\n", mp.hblkhd);
    }
    if (mp.usmblks) {
	storeAppendPrintf(sentry, "{\tspace in small blocks in use:\t%d}\n", mp.usmblks);
    }
    if (mp.fsmblks) {
	storeAppendPrintf(sentry, "{\tspace in free blocks:\t%d}\n", mp.fsmblks);
    }
    storeAppendPrintf(sentry, "{\tspace in ordinary blocks in use:\t%d KB}\n",
	mp.uordblks >> 10);
    storeAppendPrintf(sentry, "{\tspace in free ordinary blocks:\t%d KB}\n", mp.fordblks >> 10);
    if (mp.keepcost) {
	storeAppendPrintf(sentry, "{\tcost of enabling keep option:\t%d}\n", mp.keepcost);
    }
#if HAVE_EXT_MALLINFO
    storeAppendPrintf(sentry, "{\tmax size of small blocks:\t%d}\n", mp.mxfast);
    storeAppendPrintf(sentry, "{\tnumber of small blocks in a holding block:\t%d}\n",
