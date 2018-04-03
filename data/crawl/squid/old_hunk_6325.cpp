	FqdncacheStats.misses);
    storeAppendPrintf(sentry, "Blocking calls to gethostbyaddr(): %d\n",
	FqdncacheStats.ghba_calls);
    storeAppendPrintf(sentry, "FQDN Cache Contents:\n\n");

    hash_first(fqdn_table);
