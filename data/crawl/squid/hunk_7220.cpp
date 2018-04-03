 {
     StoreEntry *e = data;
     MemObject *mem = e->mem_obj;
-    debug(20, 3, "storeSwapOutHandle: '%s'\n", e->key);
+    debug(20, 3) ("storeSwapOutHandle: '%s'\n", e->key);
     if (mem == NULL)
 	fatal_dump("storeSwapOutHandle: NULL mem_obj");
     if (flag < 0) {
-	debug(20, 1, "storeSwapOutHandle: SwapOut failure (err code = %d).\n",
+	debug(20, 1) ("storeSwapOutHandle: SwapOut failure (err code = %d).\n",
 	    flag);
 	e->swap_status = NO_SWAP;
 	put_free_8k_page(mem->e_swap_buf);
