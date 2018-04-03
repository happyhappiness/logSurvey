 	IpcacheStats.negative_hits);
     storeAppendPrintf(sentry, "IPcache Misses: %d\n",
 	IpcacheStats.misses);
-    storeAppendPrintf(sentry, "Blocking calls to gethostbyname(): %d\n",
-	IpcacheStats.ghbn_calls);
-    storeAppendPrintf(sentry, "Attempts to release locked entries: %d\n",
-	IpcacheStats.release_locked);
     storeAppendPrintf(sentry, "\n\n");
     storeAppendPrintf(sentry, "IP Cache Contents:\n\n");
     storeAppendPrintf(sentry, " %-29.29s %3s %6s %6s %1s\n",
