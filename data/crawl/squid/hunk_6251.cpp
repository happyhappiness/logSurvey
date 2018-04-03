 	IpcacheStats.ghbn_calls);
     storeAppendPrintf(sentry, "Attempts to release locked entries: %d\n",
 	IpcacheStats.release_locked);
-    storeAppendPrintf(sentry, "pending queue length: %d\n", queue_length);
     storeAppendPrintf(sentry, "\n\n");
     storeAppendPrintf(sentry, "IP Cache Contents:\n\n");
     storeAppendPrintf(sentry, " %-29.29s %5s %6s %6s %1s\n",
