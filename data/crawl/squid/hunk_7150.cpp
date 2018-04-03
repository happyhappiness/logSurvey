     storeAppendPrintf(sentry, "Store Directory Statistics:\n");
     storeAppendPrintf(sentry, "Store Entries: %d\n", meta_data.store_entries);
     storeAppendPrintf(sentry, "Store Swap Size: %d KB\n", store_swap_size);
-    for (i = 0; i < ncache_dirs; i++) {
-	SD = &SwapDirs[i];
+    for (i = 0; i < Config.cacheSwap.n_configured; i++) {
+	SD = &Config.cacheSwap.swapDirs[i];
 	storeAppendPrintf(sentry, "\n");
 	storeAppendPrintf(sentry, "Store Directory #%d: %s\n", i, SD->path);
 	storeAppendPrintf(sentry, "First level subdirectories: %d\n", SD->l1);
