 	FqdncacheStats.misses);
     storeAppendPrintf(sentry, "Blocking calls to gethostbyaddr(): %d\n",
 	FqdncacheStats.ghba_calls);
+    storeAppendPrintf(sentry, "pending queue length: %d\n", queue_length);
     storeAppendPrintf(sentry, "FQDN Cache Contents:\n\n");
 
     hash_first(fqdn_table);
