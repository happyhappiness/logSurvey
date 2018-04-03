	return;
    storeAppendPrintf(sentry, "FQDN Cache Statistics:\n");
    storeAppendPrintf(sentry, "FQDNcache Entries: %d\n",
	meta_data.fqdncache_count);
    storeAppendPrintf(sentry, "FQDNcache Requests: %d\n",
	FqdncacheStats.requests);
    storeAppendPrintf(sentry, "FQDNcache Hits: %d\n",
