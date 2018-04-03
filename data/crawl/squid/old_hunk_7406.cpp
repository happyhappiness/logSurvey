	storeGetSwapSize() >> 10);
    storeAppendPrintf(sentry, "{\tStorage Mem size:\t%d KB}\n",
	store_mem_size >> 10);
    if (Config.referenceAge < 0)
        storeAppendPrintf(sentry, "{\tStorage LRU Expiration Age:\t%d days}\n",
    	    (int) storeExpiredReferenceAge());

#if HAVE_GETRUSAGE && defined(RUSAGE_SELF)
    storeAppendPrintf(sentry, "{Resource usage for %s:}\n", appname);