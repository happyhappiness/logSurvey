 
 struct StoreClientStats : public unary_function<store_client, void>
 {
-    StoreClientStats(StoreEntry *anEntry):where(anEntry),index(0){}
+    StoreClientStats(MemBuf *anEntry):where(anEntry),index(0){}
 
     void operator()(store_client const &x)
     {
         x.dumpStats(where, index++);
     }
 
-    StoreEntry *where;
+    MemBuf *where;
     size_t index;
 };
 
 void
-MemObject::stat (StoreEntry *s) const
+MemObject::stat (MemBuf * mb) const
 {
-    storeAppendPrintf(s, "\t%s %s\n",
-                      RequestMethodStr[method], log_url);
-    storeAppendPrintf(s, "\tinmem_lo: %d\n", (int) inmem_lo);
-    storeAppendPrintf(s, "\tinmem_hi: %d\n", (int) data_hdr.endOffset());
-    storeAppendPrintf(s, "\tswapout: %d bytes queued\n",
-                      (int) swapout.queue_offset);
+    memBufPrintf(mb, "\t%s %s\n",
+                 RequestMethodStr[method], log_url);
+    memBufPrintf(mb, "\tinmem_lo: %d\n", (int) inmem_lo);
+    memBufPrintf(mb, "\tinmem_hi: %d\n", (int) data_hdr.endOffset());
+    memBufPrintf(mb, "\tswapout: %d bytes queued\n",
+                 (int) swapout.queue_offset);
 
     if (swapout.sio.getRaw())
-        storeAppendPrintf(s, "\tswapout: %d bytes written\n",
-                          (int) swapout.sio->offset());
+        memBufPrintf(mb, "\tswapout: %d bytes written\n",
+                     (int) swapout.sio->offset());
 
-    StoreClientStats statsVisitor(s);
+    StoreClientStats statsVisitor(mb);
 
     for_each<StoreClientStats>(clients, statsVisitor);
 }
