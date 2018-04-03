 Rock::SwapDir::statfs(StoreEntry &e) const
 {
     storeAppendPrintf(&e, "\n");
-    storeAppendPrintf(&e, "Maximum Size: %"PRIu64" KB\n", maxSize() >> 10);
+    storeAppendPrintf(&e, "Maximum Size: %" PRIu64 " KB\n", maxSize() >> 10);
     storeAppendPrintf(&e, "Current Size: %.2f KB %.2f%%\n",
                       currentSize() / 1024.0,
                       Math::doublePercent(currentSize(), maxSize()));
