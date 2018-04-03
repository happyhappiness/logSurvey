	FqdncacheStats.requests);
    storeAppendPrintf(sentry, "FQDNcache Hits: %d\n",
	FqdncacheStats.hits);
    storeAppendPrintf(sentry, "FQDNcache Pending Hits: %d\n",
	FqdncacheStats.pending_hits);
    storeAppendPrintf(sentry, "FQDNcache Negative Hits: %d\n",
	FqdncacheStats.negative_hits);
    storeAppendPrintf(sentry, "FQDNcache Misses: %d\n",
