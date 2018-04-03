     return 0;
 }
 
-/*  use this for internal call only */
 static int
 storeCopy(const StoreEntry * e, int stateoffset, int maxSize, char *buf, int *size)
 {
-    int available_to_write = 0;
-
-    available_to_write = e->mem_obj->e_current_len - stateoffset;
-
-    if (stateoffset < e->mem_obj->e_lowest_offset) {
-	/* this should not happen. Logic race !!! */
-	debug(20, 1, "storeCopy: Client Request a chunk of data in area lower than the lowest_offset\n");
-	debug(20, 1, "           Current Lowest offset : %d\n", e->mem_obj->e_lowest_offset);
-	debug(20, 1, "           Requested offset      : %d\n", stateoffset);
-	/* can't really do anything here. Client may hang until lifetime runout. */
-	return 0;
+    int available;
+    MemObject *mem = e->mem_obj;
+    int s;
+    if (stateoffset < mem->e_lowest_offset) {
+	debug_trap("storeCopy: requested offset < e_lowest_offset");
+	return *size = 0;
     }
-    *size = (available_to_write >= maxSize) ?
-	maxSize : available_to_write;
-
-    debug(20, 6, "storeCopy: avail_to_write=%d, store_offset=%d\n",
-	*size, stateoffset);
-
-    if (*size > 0)
-	if (e->mem_obj->data->mem_copy(e->mem_obj->data, stateoffset, buf, *size) < 0)
-	    return -1;
-
-    return *size;
+    s = available = mem->e_current_len - stateoffset;
+    if (s < 0)
+	fatal_dump("storeCopy: offset > e_current_len");
+    if (s > maxSize)
+	s = maxSize;
+    debug(20, 6, "storeCopy: copying %d bytes at offset %d\n", s, stateoffset);
+    if (s > 0)
+	(void) mem->data->mem_copy(mem->data, stateoffset, buf, s);
+    return *size = s;
 }
 
 /* check if there is any client waiting for this object at all */
