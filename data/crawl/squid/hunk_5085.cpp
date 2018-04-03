 }
 
 static void
-statStoreEntry(StoreEntry * s, StoreEntry * e)
+statStoreEntry(MemBuf * mb, StoreEntry * e)
 {
     MemObject *mem = e->mem_obj;
-    storeAppendPrintf(s, "KEY %s\n", e->getMD5Text());
-    storeAppendPrintf(s, "\t%s\n", describeStatuses(e));
-    storeAppendPrintf(s, "\t%s\n", storeEntryFlags(e));
-    storeAppendPrintf(s, "\t%s\n", describeTimestamps(e));
-    storeAppendPrintf(s, "\t%d locks, %d clients, %d refs\n",
-                      (int) e->lock_count,
-                      storePendingNClients(e),
-                      (int) e->refcount);
-    storeAppendPrintf(s, "\tSwap Dir %d, File %#08X\n",
-                      e->swap_dirn, e->swap_filen);
+    memBufPrintf(mb, "KEY %s\n", e->getMD5Text());
+    memBufPrintf(mb, "\t%s\n", describeStatuses(e));
+    memBufPrintf(mb, "\t%s\n", storeEntryFlags(e));
+    memBufPrintf(mb, "\t%s\n", describeTimestamps(e));
+    memBufPrintf(mb, "\t%d locks, %d clients, %d refs\n",
+                 (int) e->lock_count,
+                 storePendingNClients(e),
+                 (int) e->refcount);
+    memBufPrintf(mb, "\tSwap Dir %d, File %#08X\n",
+                 e->swap_dirn, e->swap_filen);
 
     if (mem != NULL)
-        mem->stat (s);
+        mem->stat (mb);
 
-    storeAppendPrintf(s, "\n");
+    memBufPrintf(mb, "\n");
 }
 
 /* process objects list */
