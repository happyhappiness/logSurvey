    storeAppendPrintf(sentry, "\tRequests given to unlinkd:\t%d\n",
	Counter.unlink.requests);

    squid_getrusage(&rusage);
    cputime = rusage_cputime(&rusage);
    storeAppendPrintf(sentry, "Resource usage for %s:\n", appname);
