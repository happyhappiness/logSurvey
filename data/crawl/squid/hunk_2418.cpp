                       stats.request_hit_disk_ratio60 / fct);
 
     storeAppendPrintf(sentry, "\tStorage Swap size:\t%.0f KB\n",
-                      stats.store_swap_size);
+                      stats.store.swap.size / 1024);
 
     storeAppendPrintf(sentry, "\tStorage Swap capacity:\t%4.1f%% used, %4.1f%% free\n",
-                      Math::doublePercent(stats.store_swap_size, stats.store_swap_max_size),
-                      Math::doublePercent(stats.store_swap_max_size - stats.store_swap_size, stats.store_swap_max_size));
+                      Math::doublePercent(stats.store.swap.size, stats.store.swap.capacity),
+                      Math::doublePercent(stats.store.swap.available(), stats.store.swap.capacity));
 
     storeAppendPrintf(sentry, "\tStorage Mem size:\t%.0f KB\n",
-                      stats.store_mem_size / 1024);
+                      stats.store.mem.size / 1024);
 
-    const double mFree = max(0.0, stats.store_pages_max-stats.store_mem_used);
     storeAppendPrintf(sentry, "\tStorage Mem capacity:\t%4.1f%% used, %4.1f%% free\n",
-                      Math::doublePercent(stats.store_mem_used, stats.store_pages_max),
-                      Math::doublePercent(mFree, stats.store_pages_max));
+                      Math::doublePercent(stats.store.mem.size, stats.store.mem.capacity),
+                      Math::doublePercent(stats.store.mem.available(), stats.store.mem.capacity));
 
     storeAppendPrintf(sentry, "\tMean Object Size:\t%0.2f KB\n",
-                      stats.objects_size / fct);
+                      stats.store.swap.meanObjectSize() / 1024);
 
     storeAppendPrintf(sentry, "\tRequests given to unlinkd:\t%.0f\n",
                       stats.unlink_requests);
