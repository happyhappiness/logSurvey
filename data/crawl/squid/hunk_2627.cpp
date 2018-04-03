 void
 CossSwapDir::dump(StoreEntry &entry)const
 {
-    storeAppendPrintf(&entry, " %lu", (max_size >> 10));
+    storeAppendPrintf(&entry, " %"PRIu64, maxSize() >> 20);
     dumpOptions(&entry);
 }
 
