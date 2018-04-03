     dlink_node *m;
     assert(ip_table != NULL);
     storeAppendPrintf(sentry, "IP Cache Statistics:\n");
-    storeAppendPrintf(sentry, "IPcache Entries: %d\n",
+    storeAppendPrintf(sentry, "IPcache Entries:  %d\n",
                       memInUse(MEM_IPCACHE_ENTRY));
     storeAppendPrintf(sentry, "IPcache Requests: %d\n",
                       IpcacheStats.requests);
-    storeAppendPrintf(sentry, "IPcache Hits: %d\n",
+    storeAppendPrintf(sentry, "IPcache Hits:            %d\n",
                       IpcacheStats.hits);
-    storeAppendPrintf(sentry, "IPcache Negative Hits: %d\n",
+    storeAppendPrintf(sentry, "IPcache Negative Hits:       %d\n",
                       IpcacheStats.negative_hits);
-    storeAppendPrintf(sentry, "IPcache Misses: %d\n",
+    storeAppendPrintf(sentry, "IPcache Numeric Hits:        %d\n",
+                      IpcacheStats.numeric_hits);
+    storeAppendPrintf(sentry, "IPcache Misses:          %d\n",
                       IpcacheStats.misses);
+    storeAppendPrintf(sentry, "IPcache Invalid Request: %d\n",
+                      IpcacheStats.invalid);
     storeAppendPrintf(sentry, "\n\n");
     storeAppendPrintf(sentry, "IP Cache Contents:\n\n");
     storeAppendPrintf(sentry, " %-29.29s %3s %6s %6s %1s\n",