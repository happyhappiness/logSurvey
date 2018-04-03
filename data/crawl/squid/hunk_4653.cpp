             return 1;
         } else if (storeTooManyDiskFilesOpen()) {
             debug(20, 2)
-            ("storeCheckCachable: NO: too many disk files open\n");
+            ("StoreEntry::checkCachable: NO: too many disk files open\n");
             store_check_cachable_hist.no.too_many_open_files++;
         } else if (fdNFree() < RESERVED_FD) {
             debug(20, 2)
-            ("storeCheckCachable: NO: too many FD's open\n");
+            ("StoreEntry::checkCachable: NO: too many FD's open\n");
             store_check_cachable_hist.no.too_many_open_fds++;
         } else {
             store_check_cachable_hist.yes.Default++;
             return 1;
         }
 
-    e->releaseRequest();
+    releaseRequest();
     /* StoreEntry::releaseRequest() cleared ENTRY_CACHABLE */
     return 0;
 }
 
-static void
-storeCheckCachableStats(StoreEntry * sentry)
+void
+storeCheckCachableStats(StoreEntry *sentry)
 {
     storeAppendPrintf(sentry, "Category\t Count\n");
 
