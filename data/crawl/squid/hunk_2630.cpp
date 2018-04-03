 void
 Rock::SwapDir::statfs(StoreEntry &e) const
 {
-    const double currentSizeInKB = currentSize() / 1024.0;
     storeAppendPrintf(&e, "\n");
-    storeAppendPrintf(&e, "Maximum Size: %"PRIu64" KB\n", max_size);
+    storeAppendPrintf(&e, "Maximum Size: %"PRIu64" KB\n", maxSize() >> 10);
     storeAppendPrintf(&e, "Current Size: %.2f KB %.2f%%\n",
-                      currentSizeInKB,
-                      Math::doublePercent(currentSizeInKB, max_size));
+                      currentSize() / 1024.0,
+                      Math::doublePercent(currentSize(), maxSize()));
 
     if (map) {
         const int limit = map->entryLimit();
