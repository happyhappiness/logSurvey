     int i;
     SwapDir *SD;
     storeAppendPrintf(sentry, "Store Directory Statistics:\n");
-    storeAppendPrintf(sentry, "Store Entries          : %d\n", meta_data.store_entries);
-    storeAppendPrintf(sentry, "Maximum Swap Size      : %8d KB\n", Config.Swap.maxSize);
-    storeAppendPrintf(sentry, "Current Store Swap Size: %8d KB\n", store_swap_size);
+    storeAppendPrintf(sentry, "Store Entries          : %d\n",
+	memInUse(MEM_STOREENTRY));
+    storeAppendPrintf(sentry, "Maximum Swap Size      : %8d KB\n",
+	Config.Swap.maxSize);
+    storeAppendPrintf(sentry, "Current Store Swap Size: %8d KB\n",
+	store_swap_size);
     storeAppendPrintf(sentry, "Current Capacity       : %d%% used, %d%% free\n",
 	percent((int) store_swap_size, (int) Config.Swap.maxSize),
 	percent((int) (Config.Swap.maxSize - store_swap_size), (int) Config.Swap.maxSize));
