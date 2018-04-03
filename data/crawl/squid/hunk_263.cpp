     assert(ip_table != NULL);
     storeAppendPrintf(sentry, "IP Cache Statistics:\n");
     storeAppendPrintf(sentry, "IPcache Entries In Use:  %d\n",
-                      memInUse(MEM_IPCACHE_ENTRY));
+                      ipcache_entry::UseCount());
     storeAppendPrintf(sentry, "IPcache Entries Cached:  %d\n",
                       ipcacheCount());
     storeAppendPrintf(sentry, "IPcache Requests: %d\n",
