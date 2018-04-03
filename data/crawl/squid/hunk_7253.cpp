     StoreEntry *e = data;
     MemObject *mem = e->mem_obj;
     debug(20, 3, "storeSwapOutHandle: '%s'\n", e->key);
-    if (mem == NULL) {
-	debug(20, 0, "%s\n", storeToString(e));
-	debug_trap("Someone is swapping out a bad entry");
-	return;
-    }
+    if (mem == NULL)
+	fatal_dump("storeSwapOutHandle: NULL mem_obj");
     if (flag < 0) {
 	debug(20, 1, "storeSwapOutHandle: SwapOut failure (err code = %d).\n",
 	    flag);
