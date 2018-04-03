 void
 CossSwapDir::dump(StoreEntry &entry)const
 {
-    storeAppendPrintf(&entry, " %d", max_size >> 10);
+    storeAppendPrintf(&entry, " %Zu", (max_size >> 10));
     dumpOptions(&entry);
 }
 
