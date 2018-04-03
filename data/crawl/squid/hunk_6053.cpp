     storeAppendPrintf(sentry, "Current Capacity       : %d%% used, %d%% free\n",
 	percent((int) store_swap_size, (int) Config.Swap.maxSize),
 	percent((int) (Config.Swap.maxSize - store_swap_size), (int) Config.Swap.maxSize));
-    storeUfsDirStats(sentry);	/* XXX */
-}
 
-int
-storeDirMapBitsInUse(void)
-{
-    int i;
-    int n = 0;
-    for (i = 0; i < Config.cacheSwap.n_configured; i++)
-	n += Config.cacheSwap.swapDirs[i].map->n_files_in_map;
-    return n;
+    /* Now go through each swapdir, calling its statfs routine */
+    for (i = 0; i < Config.cacheSwap.n_configured; i++) {
+        storeAppendPrintf(sentry, "\n");
+        SD = &(Config.cacheSwap.swapDirs[i]);
+        storeAppendPrintf(sentry, "Store Directory #%d (%s): %s\n", i, SD->type,
+          storeSwapDir(i));
+        SD->statfs(SD, sentry);
+    }
 }
 
 void
