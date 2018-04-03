 void
 CossSwapDir::dump(StoreEntry &entry)const
 {
-    storeAppendPrintf(&entry, " %Zu", (max_size >> 10));
+    storeAppendPrintf(&entry, " %lu", (max_size >> 10));
     dumpOptions(&entry);
 }
 
