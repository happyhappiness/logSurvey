 void
 Store::Disk::optionObjectSizeDump(StoreEntry * e) const
 {
-    if (min_objsize != 0)
+    if (min_objsize != -1)
         storeAppendPrintf(e, " min-size=%" PRId64, min_objsize);
 
     if (max_objsize != -1)