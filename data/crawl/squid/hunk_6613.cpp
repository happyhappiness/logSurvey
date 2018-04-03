 	return;
     storeAppendPrintf(sentry, "FQDN Cache Statistics:\n");
     storeAppendPrintf(sentry, "FQDNcache Entries: %d\n",
-	meta_data.fqdncache_count);
+	memInUse(MEM_FQDNCACHE_ENTRY));
     storeAppendPrintf(sentry, "FQDNcache Requests: %d\n",
 	FqdncacheStats.requests);
     storeAppendPrintf(sentry, "FQDNcache Hits: %d\n",
