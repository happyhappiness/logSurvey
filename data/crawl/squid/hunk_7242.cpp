 
 /* same to storeCopy but also register client fd and last requested offset
  * for each client */
-int
+void
 storeClientCopy(StoreEntry * e,
-    int stateoffset,
-    int maxSize,
+    off_t offset,
+    size_t size,
     char *buf,
-    int *size,
+    STCB * callback,
     void *data)
 {
     int ci;
-    int sz;
+    size_t sz;
     MemObject *mem = e->mem_obj;
-    int available_to_write = mem->e_current_len - stateoffset;
-    if (stateoffset < mem->e_lowest_offset) {
+    if (offset < mem->e_lowest_offset) {
 	debug_trap("storeClientCopy: requested offset < lowest offset");
 	debug(20, 0, " --> %d < %d\n",
-	    stateoffset, mem->e_lowest_offset);
+	    offset, mem->e_lowest_offset);
 	debug(20, 0, "--> '%s'\n", e->url);
-	*size = 0;
-	return 0;
+	return;
     }
-    if ((ci = storeClientListSearch(mem, data)) < 0) {
-	debug_trap("storeClientCopy: Unregistered client");
-	debug(20, 0, "--> '%s'\n", e->url);
-	*size = 0;
-	return 0;
+    if ((ci = storeClientListSearch(mem, data)) < 0)
+	fatal_dump("storeClientCopy: Unregistered client");
+    mem->clients[ci].offset = offset;
+    if (offset >= mem->e_current_len) {
+	mem->clients[ci].callback = callback;
+	mem->clients[ci].copy_buf = buf;
+	mem->clients[ci].copy_size = size;
+	return;
     }
-    sz = (available_to_write >= maxSize) ? maxSize : available_to_write;
-    /* update the lowest requested offset */
-    mem->clients[ci].offset = stateoffset + sz;
-    if (sz > 0)
-	if (mem->data->mem_copy(mem->data, stateoffset, buf, sz) < 0)
-	    return -1;
+    sz = memCopy(mem->data, offset, buf, size);
+debug(0,0,"storeClientCopy: size=%d\n", sz);
+    callback(data, buf, sz);
     /* see if we can get rid of some data if we are in "delete behind" mode . */
     if (BIT_TEST(e->flag, DELETE_BEHIND))
 	storeDeleteBehind(e);
-    *size = sz;
-    return sz;
 }
 
 static int