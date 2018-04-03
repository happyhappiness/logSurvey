 	(int) e->lock_count,
 	storePendingNClients(e),
 	(int) e->refcount);
-    storeAppendPrintf(s, "\tSwap File %#08X\n",
-	e->swap_file_number);
+    storeAppendPrintf(s, "\tSwap Dir %d, File %#08X\n",
+	e->swap_dirn, e->swap_filen);
     if (mem != NULL) {
 	storeAppendPrintf(s, "\tinmem_lo: %d\n", (int) mem->inmem_lo);
 	storeAppendPrintf(s, "\tinmem_hi: %d\n", (int) mem->inmem_hi);
