    storeAppendPrintf(sentry, "{\tCPU Usage: %d%%}\n",
	percent(rusage.ru_utime.tv_sec + rusage.ru_stime.tv_sec,
	    squid_curtime - squid_starttime));
#if defined(_SQUID_SGI_) || defined(_SQUID_OSF_) || defined(BSD4_4)
    storeAppendPrintf(sentry, "{\tMaximum Resident Size: %ld KB}\n",
	rusage.ru_maxrss);
#else
    storeAppendPrintf(sentry, "{\tMaximum Resident Size: %ld KB}\n",
	(rusage.ru_maxrss * getpagesize()) >> 10);
#endif
    storeAppendPrintf(sentry, "{\tPage faults with physical i/o: %ld}\n",
	rusage.ru_majflt);
#endif
