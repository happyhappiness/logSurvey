     storeAppendPrintf(sentry, "\tStorage Mem size:\t%d KB\n",
 	(int) (store_mem_size >> 10));
 #if HEAP_REPLACEMENT
-    /* The non-LRU policies do not use referenceAge */
+    storeAppendPrintf(sentry, "\tStorage Replacement Threshold:\t%f\n",
+	heap_peepminkey(store_heap));
 #else
     storeAppendPrintf(sentry, "\tStorage LRU Expiration Age:\t%6.2f days\n",
 	(double) storeExpiredReferenceAge() / 86400.0);
