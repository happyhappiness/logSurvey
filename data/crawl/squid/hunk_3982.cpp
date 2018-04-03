 void
 String::stat(StoreEntry *entry) const
 {
-    storeAppendPrintf(entry, "%p : %d/%d \"%s\"\n",this,len_, size_, buf());
+    storeAppendPrintf(entry, "%p : %d/%d \"%s\"\n",this,len_, size_, unsafeBuf());
 }
 
 StringRegistry &
