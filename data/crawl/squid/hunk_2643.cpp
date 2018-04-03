                       (unsigned long int)StoreEntry::inUseCount());
     storeAppendPrintf(&output, "Maximum Swap Size      : %"PRIu64" KB\n",
                       maxSize());
-    storeAppendPrintf(&output, "Current Store Swap Size: %8lu KB\n",
+    storeAppendPrintf(&output, "Current Store Swap Size: %"PRIu64" KB\n",
                       currentSize());
     storeAppendPrintf(&output, "Current Capacity       : %"PRId64"%% used, %"PRId64"%% free\n",
                       Math::int64Percent(currentSize(), maxSize()),