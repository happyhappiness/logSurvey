     int ci;
     size_t sz;
     MemObject *mem = e->mem_obj;
-    if (offset < mem->e_lowest_offset) {
-	debug_trap("storeClientCopy: requested offset < lowest offset");
-	debug(20, 0, " --> %d < %d\n",
-	    offset, mem->e_lowest_offset);
-	debug(20, 0, "--> '%s'\n", e->url);
-	return;
-    }
+    struct _store_client *sc;
+    assert(seen_offset <= mem->e_current_len);
+    assert(copy_offset < mem->e_lowest_offset);
     if ((ci = storeClientListSearch(mem, data)) < 0)
 	fatal_dump("storeClientCopy: Unregistered client");
-    mem->clients[ci].offset = offset;
-    if (offset >= mem->e_current_len) {
-	mem->clients[ci].callback = callback;
-	mem->clients[ci].copy_buf = buf;
-	mem->clients[ci].copy_size = size;
+    sc = &mem->clients[ci];
+    sc->copy_offset = copy_offset;
+    sc->seen_offset = seen_offset;
+    if (seen_offset == mem->e_current_len) {
+	/* client has already seen this, wait for more */
+	sc->callback = callback;
+	sc->copy_buf = buf;
+	sc->copy_size = size;
+	sc->copy_offset = copy_offset;
 	return;
     }
-    sz = memCopy(mem->data, offset, buf, size);
+    sz = memCopy(mem->data, copy_offset, buf, size);
     callback(data, buf, sz);
     /* see if we can get rid of some data if we are in "delete behind" mode . */
     if (BIT_TEST(e->flag, DELETE_BEHIND))