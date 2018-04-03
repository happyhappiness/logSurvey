     storeAppendPrintf(&output, "Store Directory Statistics:\n");
     storeAppendPrintf(&output, "Store Entries          : %lu\n",
                       (unsigned long int)StoreEntry::inUseCount());
-    storeAppendPrintf(&output, "Maximum Swap Size      : %8ld KB\n",
-                      (long int) maxSize());
+    storeAppendPrintf(&output, "Maximum Swap Size      : %"PRIu64" KB\n",
+                      maxSize());
     storeAppendPrintf(&output, "Current Store Swap Size: %8lu KB\n",
                       store_swap_size);
-    // XXX : below capacity display calculation breaks with int overflow on 64-bit systems
-    storeAppendPrintf(&output, "Current Capacity       : %d%% used, %d%% free\n",
-                      Math::intPercent((int) store_swap_size, (int) maxSize()),
-                      Math::intPercent((int) (maxSize() - store_swap_size), (int) maxSize()));
+    storeAppendPrintf(&output, "Current Capacity       : %"PRId64"%% used, %"PRId64"%% free\n",
+                      Math::int64Percent(store_swap_size, maxSize()),
+                      Math::int64Percent((maxSize() - store_swap_size), maxSize()));
     /* FIXME Here we should output memory statistics */
 
     /* now the swapDir */
     swapDir->stat(output);
 }
 
 /* if needed, this could be taught to cache the result */
-size_t
+uint64_t
 StoreController::maxSize() const
 {
     /* TODO: include memory cache ? */
     return swapDir->maxSize();
 }
 
-size_t
+uint64_t
 StoreController::minSize() const
 {
     /* TODO: include memory cache ? */