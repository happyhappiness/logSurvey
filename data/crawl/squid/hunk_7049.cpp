     STCB * callback,
     void *data)
 {
-    int ci;
     size_t sz;
     MemObject *mem = e->mem_obj;
     struct _store_client *sc;
     static int recurse_detect = 0;
-    assert(seen_offset <= mem->e_current_len);
-    assert(copy_offset >= mem->e_lowest_offset);
     assert(recurse_detect < 3);	/* could == 1 for IMS not modified's */
-    debug(20, 3) ("storeClientCopy: %s, seen %d want %d, size %d, cb %p, cbdata %p\n",
+    debug(20, 3) ("storeClientCopy: %s, seen %d, want %d, size %d, cb %p, cbdata %p\n",
 	e->key,
 	(int) seen_offset,
 	(int) copy_offset,
 	(int) size,
 	callback,
 	data);
-    if ((ci = storeClientListSearch(mem, data)) < 0)
-	fatal_dump("storeClientCopy: Unregistered client");
-    sc = &mem->clients[ci];
+    sc = storeClientListSearch(mem, data);
+    assert(sc != NULL);
     sc->copy_offset = copy_offset;
     sc->seen_offset = seen_offset;
-    if (seen_offset == mem->e_current_len) {
+    sc->callback = callback;
+    sc->copy_buf = buf;
+    sc->copy_size = size;
+    sc->copy_offset = copy_offset;
+    if (e->store_status == STORE_PENDING && seen_offset == mem->inmem_hi) {
 	/* client has already seen this, wait for more */
-	sc->callback = callback;
-	sc->copy_buf = buf;
-	sc->copy_size = size;
-	sc->copy_offset = copy_offset;
+	debug(20, 3) ("storeClientCopy: Waiting for more\n");
 	return;
     }
-    if (BIT_TEST(e->flag, DELETE_BEHIND))
-	storeDeleteBehind(e);
-    sz = memCopy(mem->data, copy_offset, buf, size);
-    recurse_detect++;
-    callback(data, buf, sz);
+    if (copy_offset >= mem->inmem_lo && mem->inmem_lo < mem->inmem_hi) {
+	/* What the client wants is in memory */
+	debug(20, 3) ("storeClientCopy: Copying from memory\n");
+	sz = memCopy(mem->data, copy_offset, buf, size);
+	recurse_detect++;
+	sc->callback = NULL;
+	callback(data, buf, sz);
+    } else if (sc->swapin_fd < 0) {
+	debug(20, 3) ("storeClientCopy: Need to open swap in file\n");
+	/* gotta open the swapin file */
+	assert(copy_offset == 0);
+	storeSwapInStart(e, storeClientCopyFileOpened, sc);
+    } else {
+	debug(20, 3) ("storeClientCopy: reading from disk FD %d\n",
+	    sc->swapin_fd);
+	storeClientCopyFileRead(sc);
+    }
     recurse_detect--;
 }
 
+static void
+storeClientCopyFileOpened(int fd, void *data)
+{
+    struct _store_client *sc = data;
+    if (fd < 0) {
+	debug(20, 1) ("storeClientCopyFileOpened: failed\n");
+	sc->callback(sc->callback_data, sc->copy_buf, -1);
+	return;
+    }
+    sc->swapin_fd = fd;
+    storeClientCopyFileRead(sc);
+}
+
+static void
+storeClientCopyFileRead(struct _store_client *sc)
+{
+    file_read(sc->swapin_fd,
+	sc->copy_buf,
+	sc->copy_size,
+	sc->copy_offset,
+	storeClientCopyHandleRead,
+	sc);
+}
+
+static void
+storeClientCopyHandleRead(int fd, const char *buf, int len, int flag, void *data)
+{
+    struct _store_client *sc = data;
+    debug(20, 3) ("storeClientCopyHandleRead: FD %d\n", fd);
+    debug(20, 3) ("storeClientCopyHandleRead: buf = %p\n", buf);
+    debug(20, 3) ("storeClientCopyHandleRead: len = %d\n", len);
+    debug(20, 3) ("storeClientCopyHandleRead: flag = %d\n", flag);
+    debug(20, 3) ("storeClientCopyHandleRead: data = %p\n", data);
+    sc->callback(sc->callback_data, sc->copy_buf, len);
+}
+
+
 static int
 storeEntryValidLength(const StoreEntry * e)
 {
