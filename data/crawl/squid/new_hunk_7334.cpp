	store_mem_size >> 10);
    storeAppendPrintf(sentry, "{\tStorage LRU Expiration Age:\t%6.2f days}\n",
	(double) storeExpiredReferenceAge() / 86400.0);
    storeAppendPrintf(sentry, "{\tRequests given to unlinkd:\t%d}\n",
	unlinkd_count);
    storeAppendPrintf(sentry, "{\tUnused fileno stack count:\t%d}\n",
	fileno_stack_count);

#if HAVE_GETRUSAGE && defined(RUSAGE_SELF)
    storeAppendPrintf(sentry, "{Resource usage for %s:}\n", appname);
