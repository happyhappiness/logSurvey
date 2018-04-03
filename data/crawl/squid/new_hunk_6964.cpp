    storeAppendPrintf(sentry, "{\tStorage LRU Expiration Age:\t%6.2f days}\n",
	(double) storeExpiredReferenceAge() / 86400.0);
    storeAppendPrintf(sentry, "{\tRequests given to unlinkd:\t%d}\n",
	Counter.unlink.requests);
    storeAppendPrintf(sentry, "{\tUnused fileno stack count:\t%d}\n",
	fileno_stack_count);

    squid_getrusage(&rusage);
    cputime = rusage_cputime(&rusage);
    storeAppendPrintf(sentry, "{Resource usage for %s:}\n", appname);
    storeAppendPrintf(sentry, "{\tUP Time:\t%.3f seconds}\n", runtime);
    storeAppendPrintf(sentry, "{\tCPU Time:\t%.3f seconds}\n", cputime);
    storeAppendPrintf(sentry, "{\tCPU Usage:\t%d%%}\n",
	dpercent(cputime, runtime));
    storeAppendPrintf(sentry, "{\tMaximum Resident Size: %ld KB}\n",
	rusage_maxrss(&rusage));
    storeAppendPrintf(sentry, "{\tPage faults with physical i/o: %ld}\n",
	rusage_pagefaults(&rusage));

#if HAVE_MSTATS && HAVE_GNUMALLOC_H
    ms = mstats();
