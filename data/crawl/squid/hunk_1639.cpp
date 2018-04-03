 {
     storeAppendPrintf(&e, "\n\nShared Memory Cache\n");
 
-    storeAppendPrintf(&e, "Maximum Size: %.0f KB\n", Config.memMaxSize/1024.0);
+    storeAppendPrintf(&e, "Maximum Size: %.0f KB\n", maxSize()/1024.0);
+    storeAppendPrintf(&e, "Current Size: %.2f KB %.2f%%\n",
+                      currentSize() / 1024.0,
+                      Math::doublePercent(currentSize(), maxSize()));
 
     if (map) {
         const int limit = map->entryLimit();
