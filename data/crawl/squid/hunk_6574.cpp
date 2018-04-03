     storeAppendPrintf(sentry, "\tStorage Swap size:\t%d KB\n",
 	store_swap_size);
     storeAppendPrintf(sentry, "\tStorage Mem size:\t%d KB\n",
-	store_mem_size >> 10);
+	(int) (store_mem_size >> 10));
     storeAppendPrintf(sentry, "\tStorage LRU Expiration Age:\t%6.2f days\n",
 	(double) storeExpiredReferenceAge() / 86400.0);
     storeAppendPrintf(sentry, "\tRequests given to unlinkd:\t%d\n",
