     MemObject *mem = e->mem_obj;
     debug(20, 2, "storeSwapInHandle: '%s'\n", e->key);
 
+    if (mem == NULL)		/* XXX remove later */
+	fatal_dump(NULL);
+
     if ((flag < 0) && (flag != DISK_EOF)) {
 	debug(20, 0, "storeSwapInHandle: SwapIn failure (err code = %d).\n", flag);
 	put_free_8k_page(mem->e_swap_buf);
