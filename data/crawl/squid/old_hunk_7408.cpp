    storeAppendPrintf(sentry, "{\tCPU Usage: %d%%}\n",
	percent(rusage.ru_utime.tv_sec + rusage.ru_stime.tv_sec,
	    squid_curtime - squid_starttime));
#if defined(_SQUID_SGI_) || defined(_SQUID_OSF_)
    storeAppendPrintf(sentry, "{\tProcess Size: rss %ld KB}\n",
	rusage.ru_maxrss);
#else /* _SQUID_SGI_ */
    storeAppendPrintf(sentry, "{\tProcess Size: rss %ld KB}\n",
	(rusage.ru_maxrss * getpagesize()) >> 10);
#endif /* _SQUID_SGI_ */
    storeAppendPrintf(sentry, "{\tPage faults with physical i/o: %ld}\n",
	rusage.ru_majflt);
#endif
