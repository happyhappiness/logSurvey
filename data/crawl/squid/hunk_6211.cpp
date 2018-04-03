 static void
 storeCheckCachableStats(StoreEntry * sentry)
 {
+    storeAppendPrintf(sentry, "Category\t Count\n");
+
     storeAppendPrintf(sentry, "no.non_get\t%d\n",
 	store_check_cachable_hist.no.non_get);
     storeAppendPrintf(sentry, "no.not_entry_cachable\t%d\n",