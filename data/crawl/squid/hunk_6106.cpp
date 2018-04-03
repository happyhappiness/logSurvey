     storeAppendPrintf(sentry, "Current Capacity       : %d%% used, %d%% free\n",
 	percent((int) store_swap_size, (int) Config.Swap.maxSize),
 	percent((int) (Config.Swap.maxSize - store_swap_size), (int) Config.Swap.maxSize));
-    storeUfsDirStats(sentry);
+    storeUfsDirStats(sentry);	/* XXX */
 }
 
 int
