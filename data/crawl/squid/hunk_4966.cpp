 void
 MemObject::stat (MemBuf * mb) const
 {
-    memBufPrintf(mb, "\t%s %s\n",
-                 RequestMethodStr[method], log_url);
-    memBufPrintf(mb, "\tinmem_lo: %d\n", (int) inmem_lo);
-    memBufPrintf(mb, "\tinmem_hi: %d\n", (int) data_hdr.endOffset());
-    memBufPrintf(mb, "\tswapout: %d bytes queued\n",
-                 (int) swapout.queue_offset);
+    mb->Printf("\t%s %s\n",
+               RequestMethodStr[method], log_url);
+    mb->Printf("\tinmem_lo: %d\n", (int) inmem_lo);
+    mb->Printf("\tinmem_hi: %d\n", (int) data_hdr.endOffset());
+    mb->Printf("\tswapout: %d bytes queued\n",
+               (int) swapout.queue_offset);
 
     if (swapout.sio.getRaw())
-        memBufPrintf(mb, "\tswapout: %d bytes written\n",
-                     (int) swapout.sio->offset());
+        mb->Printf("\tswapout: %d bytes written\n",
+                   (int) swapout.sio->offset());
 
     StoreClientStats statsVisitor(mb);
 
