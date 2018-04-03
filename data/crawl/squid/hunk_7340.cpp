 
     storeAppendPrintf(sentry, "{Cache information for %s:}\n",
 	appname);
-    storeAppendPrintf(sentry, "{\tStorage Swap size:\t%d MB}\n",
-	store_swap_size >> 10);
+    storeAppendPrintf(sentry, "{\tStorage Swap size:\t%d KB}\n",
+	store_swap_size);
     storeAppendPrintf(sentry, "{\tStorage Mem size:\t%d KB}\n",
 	store_mem_size >> 10);
     storeAppendPrintf(sentry, "{\tStorage LRU Expiration Age:\t%6.2f days}\n",
