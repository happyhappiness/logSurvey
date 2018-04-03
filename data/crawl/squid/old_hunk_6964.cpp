    storeAppendPrintf(sentry, "{\tStorage LRU Expiration Age:\t%6.2f days}\n",
	(double) storeExpiredReferenceAge() / 86400.0);
    storeAppendPrintf(sentry, "{\tRequests given to unlinkd:\t%d}\n",
	unlinkd_count);
    storeAppendPrintf(sentry, "{\tUnused fileno stack count:\t%d}\n",
	fileno_stack_count);

#if HAVE_GETRUSAGE && defined(RUSAGE_SELF)
    storeAppendPrintf(sentry, "{Resource usage for %s:}\n", appname);
#ifdef _SQUID_SOLARIS_
    /* Solaris 2.5 has getrusage() permission bug -- Arjan de Vet */
    enter_suid();
#endif
    getrusage(RUSAGE_SELF, &rusage);
#ifdef _SQUID_SOLARIS_
    leave_suid();
#endif
    storeAppendPrintf(sentry, "{\tCPU Time: %d seconds (%d user %d sys)}\n",
	(int) rusage.ru_utime.tv_sec + (int) rusage.ru_stime.tv_sec,
	(int) rusage.ru_utime.tv_sec,
	(int) rusage.ru_stime.tv_sec);
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

#if HAVE_MSTATS && HAVE_GNUMALLOC_H
    ms = mstats();
