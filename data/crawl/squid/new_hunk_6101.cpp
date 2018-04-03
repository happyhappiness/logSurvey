	store_swap_size);
    storeAppendPrintf(sentry, "\tStorage Mem size:\t%d KB\n",
	(int) (store_mem_size >> 10));
#if HEAP_REPLACEMENT
    /* The non-LRU policies do not use referenceAge */
#else
    storeAppendPrintf(sentry, "\tStorage LRU Expiration Age:\t%6.2f days\n",
	(double) storeExpiredReferenceAge() / 86400.0);
#endif
    storeAppendPrintf(sentry, "\tMean Object Size:\t%0.2f KB\n",
	n_disk_objects ? (double) store_swap_size / n_disk_objects : 0.0);
    storeAppendPrintf(sentry, "\tRequests given to unlinkd:\t%d\n",
