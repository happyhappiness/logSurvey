     assert(e->mem_status == NOT_IN_MEMORY);
     if (!BIT_TEST(e->flag, ENTRY_VALIDATED)) {
 	/* Invoke a store abort that should free the memory object */
-	(ctrlp->callback) (ctrlp->callback_data, -1);
+	(ctrlp->callback) (-1, ctrlp->callback_data);
 	xfree(ctrlp);
 	return;
     }
     ctrlp->path = xstrdup(storeSwapFullPath(e->swap_file_number, NULL));
-    file_open(ctrlp->path, O_RDONLY, storeSwapInStartComplete, ctrlp);
+    file_open(ctrlp->path, O_RDONLY, storeSwapInFileOpened, ctrlp);
 }
 
 static void
-storeSwapInStartComplete(void *data, int fd)
+storeSwapInFileOpened(void *data, int fd)
 {
     swapin_ctrl_t *ctrlp = (swapin_ctrl_t *) data;
     StoreEntry *e = ctrlp->e;
-    MemObject *mem = e->mem_obj;
     assert(e->mem_obj != NULL);
     assert(e->mem_status == NOT_IN_MEMORY);
-    assert(e->swap_status == SWAP_OK);
+    assert(e->swap_status == SWAPOUT_DONE);
     if (fd < 0) {
 	debug(20, 0) ("storeSwapInStartComplete: Failed for '%s'\n", e->url);
 	/* Invoke a store abort that should free the memory object */
-	(ctrlp->callback) (ctrlp->callback_data, -1);
+	(ctrlp->callback) (-1, ctrlp->callback_data);
 	xfree(ctrlp->path);
 	xfree(ctrlp);
 	return;
     }
-    storeSetMemStatus(e, SWAPPING_IN);
-    mem->swapin_fd = (short) fd;
     debug(20, 5) ("storeSwapInStart: initialized swap file '%s' for '%s'\n",
 	ctrlp->path, e->url);
-    mem->data = new_MemObjectData();
-    mem->swap_offset = 0;
-    mem->e_swap_buf = get_free_8k_page();
-    /* start swapping daemon */
-    file_read(fd,
-	mem->e_swap_buf,
-	SWAP_BUF,
-	mem->swap_offset,
-	storeSwapInHandle,
-	e);
-    (ctrlp->callback) (ctrlp->callback_data, 0);
+    (ctrlp->callback) (fd, ctrlp->callback_data);
     xfree(ctrlp->path);
     xfree(ctrlp);
 }
 
-static void
-storeSwapOutHandle(int fd, int flag, size_t len, void *data)
-{
-    StoreEntry *e = data;
-    MemObject *mem = e->mem_obj;
-    debug(20, 3) ("storeSwapOutHandle: '%s'\n", e->key);
-    if (mem == NULL)
-	fatal_dump("storeSwapOutHandle: NULL mem_obj");
-    if (flag < 0) {
-	debug(20, 1) ("storeSwapOutHandle: SwapOut failure (err code = %d).\n",
-	    flag);
-	e->swap_status = NO_SWAP;
-	put_free_8k_page(mem->e_swap_buf);
-	file_close(fd);
-	if (e->swap_file_number != -1) {
-	    storePutUnusedFileno(e->swap_file_number);
-	    e->swap_file_number = -1;
-	}
-	storeRelease(e);
-	if (flag == DISK_NO_SPACE_LEFT) {
-	    /* reduce the swap_size limit to the current size. */
-	    Config.Swap.maxSize = store_swap_size;
-	    storeConfigure();
-	}
-	return;
-    }
-    debug(20, 6) ("storeSwapOutHandle: e->swap_offset    = %d\n", mem->swap_offset);
-    debug(20, 6) ("storeSwapOutHandle: e->e_swap_buf_len = %d\n", mem->e_swap_buf_len);
-    debug(20, 6) ("storeSwapOutHandle: e->object_len     = %d\n", e->object_len);
-    debug(20, 6) ("storeSwapOutHandle: store_swap_size   = %dk\n", store_swap_size);
-    mem->swap_offset += mem->e_swap_buf_len;
-    /* round up */
-    storeDirUpdateSwapSize(e->swap_file_number, mem->e_swap_buf_len, 1);
-    if (mem->swap_offset >= e->object_len) {
-	/* swapping complete */
-	e->swap_status = SWAP_OK;
-	file_close(mem->swapout_fd);
-	storeLog(STORE_LOG_SWAPOUT, e);
-	debug(20, 5) ("storeSwapOutHandle: SwapOut complete: '%s' to %s.\n",
-	    e->url, storeSwapFullPath(e->swap_file_number, NULL));
-	put_free_8k_page(mem->e_swap_buf);
-	storeDirSwapLog(e);
-	HTTPCacheInfo->proto_newobject(HTTPCacheInfo,
-	    mem->request->protocol,
-	    e->object_len,
-	    FALSE);
-	/* check if it's request to be released. */
-	if (BIT_TEST(e->flag, RELEASE_REQUEST))
-	    storeRelease(e);
-	else if (storeShouldPurgeMem(e))
-	    storePurgeMem(e);
-	else {
-	    requestUnlink(mem->request);
-	    mem->request = NULL;
-	}
-	return;
-    }
-    /* write some more data, reschedule itself. */
-    if (storeCopy(e, mem->swap_offset, SWAP_BUF, mem->e_swap_buf, &(mem->e_swap_buf_len)) < 0) {
-	debug(20, 1) ("storeSwapOutHandle: SwapOut failure (err code = %d).\n",
-	    flag);
-	e->swap_status = NO_SWAP;
-	put_free_8k_page(mem->e_swap_buf);
-	file_close(fd);
-	if (e->swap_file_number != -1) {
-	    storeDirMapBitReset(e->swap_file_number);
-	    safeunlink(storeSwapFullPath(e->swap_file_number, NULL), 0);
-	    e->swap_file_number = -1;
-	}
-	storeRelease(e);
-	return;
-    }
-    file_write(mem->swapout_fd,
-	mem->e_swap_buf,
-	mem->e_swap_buf_len,
-	storeSwapOutHandle,
-	e,
-	NULL);
-    return;
-}
-
-/* start swapping object to disk */
-static void
-storeSwapOutStart(StoreEntry * e)
-{
-    swapout_ctrl_t *ctrlp;
-    LOCAL_ARRAY(char, swapfilename, SQUID_MAXPATHLEN);
-    if ((e->swap_file_number = storeGetUnusedFileno()) < 0)
-	e->swap_file_number = storeDirMapAllocate();
-    storeSwapFullPath(e->swap_file_number, swapfilename);
-    ctrlp = xmalloc(sizeof(swapout_ctrl_t));
-    ctrlp->swapfilename = xstrdup(swapfilename);
-    ctrlp->e = e;
-    ctrlp->oldswapstatus = e->swap_status;
-    e->swap_status = SWAPPING_OUT;
-    file_open(swapfilename,
-	O_WRONLY | O_CREAT | O_TRUNC,
-	storeSwapOutStartComplete,
-	ctrlp);
-}
-
-static void
-storeSwapOutStartComplete(void *data, int fd)
-{
-    swapout_ctrl_t *ctrlp = data;
-    int oldswapstatus = ctrlp->oldswapstatus;
-    char *swapfilename = ctrlp->swapfilename;
-    StoreEntry *e = ctrlp->e;
-    int x;
-    MemObject *mem;
-    xfree(ctrlp);
-    if (fd < 0) {
-	debug(20, 0) ("storeSwapOutStart: Unable to open swapfile: %s\n",
-	    swapfilename);
-	storeDirMapBitReset(e->swap_file_number);
-	e->swap_file_number = -1;
-	if (e->swap_status == SWAPPING_OUT)
-	    e->swap_status = oldswapstatus;
-	xfree(swapfilename);
-	return;
-    }
-    mem = e->mem_obj;
-    mem->swapout_fd = (short) fd;
-    debug(20, 5) ("storeSwapOutStart: Begin SwapOut '%s' to FD %d FILE %s.\n",
-	e->url, fd, swapfilename);
-    debug(20, 5) ("swap_file_number=%08X\n", e->swap_file_number);
-    e->swap_status = SWAPPING_OUT;
-    mem->swap_offset = 0;
-    mem->e_swap_buf = get_free_8k_page();
-    mem->e_swap_buf_len = 0;
-    x = storeCopy(e,
-	0,
-	SWAP_BUF,
-	mem->e_swap_buf,
-	&mem->e_swap_buf_len);
-    if (x < 0) {
-	debug(20, 1) ("storeCopy returned %d for '%s'\n", x, e->key);
-	e->swap_file_number = -1;
-	file_close(fd);
-	storeDirMapBitReset(e->swap_file_number);
-	e->swap_file_number = -1;
-	safeunlink(swapfilename, 1);
-	if (e->swap_status == SWAPPING_OUT)
-	    e->swap_status = oldswapstatus;
-	xfree(swapfilename);
-	return;
-    }
-    /* start swapping daemon */
-    x = file_write(mem->swapout_fd,
-	mem->e_swap_buf,
-	mem->e_swap_buf_len,
-	storeSwapOutHandle,
-	e,
-	NULL);
-    if (x != DISK_OK)
-	fatal_dump(NULL);	/* This shouldn't happen */
-    xfree(swapfilename);
-}
-
 /* recreate meta data from disk image in swap directory */
 /* Add one swap file at a time from disk storage */
 static void
