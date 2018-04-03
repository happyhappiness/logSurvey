 void
 UFSSwapDir::dump(StoreEntry & entry) const
 {
-    storeAppendPrintf(&entry, " %d %d %d",
-                      max_size >> 10,
-                      l1,
-                      l2);
+    storeAppendPrintf(&entry, " %Zu %d %d", (max_size >> 10), l1, l2);
     dumpOptions(&entry);
 }
 
