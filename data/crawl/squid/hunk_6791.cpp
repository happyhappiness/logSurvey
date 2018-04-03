 	FqdncacheStats.misses);
     storeAppendPrintf(sentry, "Blocking calls to gethostbyaddr(): %d\n",
 	FqdncacheStats.ghba_calls);
-    storeAppendPrintf(sentry, "dnsserver avg service time: %d msec\n",
-	FqdncacheStats.avg_svc_time);
     storeAppendPrintf(sentry, "FQDN Cache Contents:\n\n");
 
     next = (fqdncache_entry *) hash_first(fqdn_table);
