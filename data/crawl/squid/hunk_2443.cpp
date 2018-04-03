 CossSwapDir::statfs(StoreEntry & sentry) const
 {
     storeAppendPrintf(&sentry, "\n");
-    storeAppendPrintf(&sentry, "Maximum Size: %lu KB\n", max_size);
-    storeAppendPrintf(&sentry, "Current Size: %lu KB\n", cur_size);
+    storeAppendPrintf(&sentry, "Maximum Size: %"PRIu64" KB\n", maxSize() >> 10);
+    storeAppendPrintf(&sentry, "Current Size: %.2f KB\n", currentSize() / 1024.0);
     storeAppendPrintf(&sentry, "Percent Used: %0.2f%%\n",
-                      (100.0 * (double)cur_size / (double)max_size) );
+                      Math::doublePercent(currentSize(), maxSize()) );
     storeAppendPrintf(&sentry, "Number of object collisions: %d\n", (int) numcollisions);
 #if 0
     /* is this applicable? I Hope not .. */
