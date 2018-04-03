 	debug_trap("storeSwapInStart: mem_obj already present");
 	return -1;
     }
-    e->mem_obj = mem = new_MemObject();
+    ctrlp = xmalloc(sizeof(swapin_ctrl_t));
+    ctrlp->e = e;
+    ctrlp->callback = callback;
+    ctrlp->callback_data = callback_data;
+    if (BIT_TEST(e->flag, ENTRY_VALIDATED)) {
+	storeSwapInValidateComplete(ctrlp, 0);
+	return 0;
+    }
+    storeValidate(e, storeSwapInValidateComplete, ctrlp);
+    return 0;
+}
 
-    path = storeSwapFullPath(e->swap_file_number, NULL);
-    if ((fd = file_open(path, NULL, O_RDONLY)) < 0) {
-	debug(20, 0, "storeSwapInStart: Failed for '%s'\n", e->url);
+
+static void
+storeSwapInValidateComplete(void *data, int status)
+{
+    swapin_ctrl_t *ctrlp = (swapin_ctrl_t *) data;
+    char *path;
+    StoreEntry *e;
+    e = ctrlp->e;
+    if (!BIT_TEST(e->flag, ENTRY_VALIDATED)) {
 	storeSetMemStatus(e, NOT_IN_MEMORY);
 	/* Invoke a store abort that should free the memory object */
-	return -1;
+	(ctrlp->callback) (ctrlp->callback_data, -1);
+	xfree(ctrlp);
+	return;
     }
+    path = storeSwapFullPath(e->swap_file_number, NULL);
+    ctrlp->path = xstrdup(path);
+    file_open(path, NULL, O_RDONLY, storeSwapInStartComplete, ctrlp);
+}
+
+static void
+storeSwapInStartComplete(void *data, int fd)
+{
+    MemObject *mem = NULL;
+    swapin_ctrl_t *ctrlp = (swapin_ctrl_t *) data;
+    StoreEntry *e = ctrlp->e;
+    if (fd < 0) {
+	debug(20, 0, "storeSwapInStartComplete: Failed for '%s'\n", e->url);
+	if (!e->mem_obj)
+	    storeSetMemStatus(e, NOT_IN_MEMORY);
+	/* Invoke a store abort that should free the memory object */
+	(ctrlp->callback) (ctrlp->callback_data, -1);
+	xfree(ctrlp->path);
+	xfree(ctrlp);
+	return;
+    }
+    if (e->mem_obj)
+	fatal_dump("storeSwapInStartComplete already exists");
+    if (e->swap_status != SWAP_OK)
+	fatal_dump("storeSwapInStartComplete: bad swap_status");
+    storeSetMemStatus(e, SWAPPING_IN);
+    mem = e->mem_obj = new_MemObject();
     mem->swapin_fd = (short) fd;
     debug(20, 5, "storeSwapInStart: initialized swap file '%s' for '%s'\n",
-	path, e->url);
-    storeSetMemStatus(e, SWAPPING_IN);
+	ctrlp->path, e->url);
     mem->data = new_MemObjectData();
     mem->swap_offset = 0;
     mem->e_swap_buf = get_free_8k_page();
-
     /* start swapping daemon */
     file_read(fd,
 	mem->e_swap_buf,
 	SWAP_BUF,
 	mem->swap_offset,
 	(FILE_READ_HD) storeSwapInHandle,
 	(void *) e);
-    mem->swapin_complete_handler = swapin_complete_handler;
-    mem->swapin_complete_data = swapin_complete_data;
-    return 0;
+    (ctrlp->callback) (ctrlp->callback_data, 0);
+    xfree(ctrlp->path);
+    xfree(ctrlp);
 }
 
 static void
