 
     storelog = logfileOpen(Config.Log.store, 0, 1);
 }
+
+void
+storeLogRegisterWithCacheManager(CacheManager & manager)
+{
+    manager.registerAction("store_log_tags",
+	"Histogram of store.log tags",
+	storeLogTagsHist, 0, 1);
+}
+
+void
+storeLogTagsHist(StoreEntry *e)
+{
+    int tag;
+    for (tag = 0; tag <= STORE_LOG_SWAPOUTFAIL; tag++) {
+	storeAppendPrintf(e, "%s %d\n",
+	    storeLogTags[tag],
+	    storeLogTagsCounts[tag]);
+    }
+}