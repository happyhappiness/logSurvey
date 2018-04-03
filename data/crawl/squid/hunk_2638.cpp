 void
 CossSwapDir::statfs(StoreEntry & sentry) const
 {
+    const double currentSizeInKB = currentSize() / 1024.0;
     storeAppendPrintf(&sentry, "\n");
     storeAppendPrintf(&sentry, "Maximum Size: %lu KB\n", max_size);
-    storeAppendPrintf(&sentry, "Current Size: %lu KB\n", cur_size);
+    storeAppendPrintf(&sentry, "Current Size: %.2f KB\n", currentSizeInKB);
     storeAppendPrintf(&sentry, "Percent Used: %0.2f%%\n",
-                      (100.0 * (double)cur_size / (double)max_size) );
+                      Math::doublePercent(currentSizeInKB, max_size) );
     storeAppendPrintf(&sentry, "Number of object collisions: %d\n", (int) numcollisions);
 #if 0
     /* is this applicable? I Hope not .. */
