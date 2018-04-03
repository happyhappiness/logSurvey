	FqdncacheStats.negative_hits);
    storeAppendPrintf(sentry, "FQDNcache Misses: %d\n",
	FqdncacheStats.misses);
    storeAppendPrintf(sentry, "Blocking calls to gethostbyaddr(): %d\n",
	FqdncacheStats.ghba_calls);
    storeAppendPrintf(sentry, "FQDN Cache Contents:\n\n");
    storeAppendPrintf(sentry, "%-15.15s %3s %3s %3s %s\n",
	"Address", "Flg", "TTL", "Cnt", "Hostnames");
