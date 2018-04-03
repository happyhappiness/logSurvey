         mb->Printf("\tswapout: %" PRId64 " bytes written\n",
                    (int64_t) swapout.sio->offset());
 
+    if (xitTable.index >= 0)
+        mb->Printf("\ttransient index: %d state: %d\n",
+                   xitTable.index, xitTable.io);
+    if (memCache.index >= 0)
+        mb->Printf("\tmem-cache index: %d state: %d offset: %" PRId64 "\n",
+                   memCache.index, memCache.io, memCache.offset);
+    if (object_sz >= 0)
+        mb->Printf("\tobject_sz: %" PRId64 "\n", object_sz);
+    if (smpCollapsed)
+        mb->Printf("\tsmp-collapsed\n");
+
     StoreClientStats statsVisitor(mb);
 
     for_each<StoreClientStats>(clients, statsVisitor);
