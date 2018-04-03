     storeAppendPrintf(sentry, "Cache information for %s:\n",
                       appname);
 
-    storeAppendPrintf(sentry, "\tHits as % of all requests:\t5min: %3.1f%%, 60min: %3.1f%%\n",
+    storeAppendPrintf(sentry, "\tHits as %% of all requests:\t5min: %3.1f%%, 60min: %3.1f%%\n",
                       statRequestHitRatio(5),
                       statRequestHitRatio(60));
 
-    storeAppendPrintf(sentry, "\tHits as % of bytes sent:\t5min: %3.1f%%, 60min: %3.1f%%\n",
+    storeAppendPrintf(sentry, "\tHits as %% of bytes sent:\t5min: %3.1f%%, 60min: %3.1f%%\n",
                       statByteHitRatio(5),
                       statByteHitRatio(60));
 
-    storeAppendPrintf(sentry, "\tMemory hits as % of hit requests:\t5min: %3.1f%%, 60min: %3.1f%%\n",
+    storeAppendPrintf(sentry, "\tMemory hits as %% of hit requests:\t5min: %3.1f%%, 60min: %3.1f%%\n",
                       statRequestHitMemoryRatio(5),
                       statRequestHitMemoryRatio(60));
 
-    storeAppendPrintf(sentry, "\tDisk hits as % of hit requests:\t5min: %3.1f%%, 60min: %3.1f%%\n",
+    storeAppendPrintf(sentry, "\tDisk hits as %% of hit requests:\t5min: %3.1f%%, 60min: %3.1f%%\n",
                       statRequestHitDiskRatio(5),
                       statRequestHitDiskRatio(60));
 