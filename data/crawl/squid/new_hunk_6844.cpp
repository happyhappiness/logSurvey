	(double) storeExpiredReferenceAge() / 86400.0);
    storeAppendPrintf(sentry, "{\tRequests given to unlinkd:\t%d}\n",
	Counter.unlink.requests);

    squid_getrusage(&rusage);
    cputime = rusage_cputime(&rusage);