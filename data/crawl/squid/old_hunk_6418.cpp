	(int) (store_mem_size >> 10));
    storeAppendPrintf(sentry, "\tStorage LRU Expiration Age:\t%6.2f days\n",
	(double) storeExpiredReferenceAge() / 86400.0);
    storeAppendPrintf(sentry, "\tRequests given to unlinkd:\t%d\n",
	Counter.unlink.requests);

