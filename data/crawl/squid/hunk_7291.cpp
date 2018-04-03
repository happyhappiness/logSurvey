 
 /* must close a disk file */
 
-int
+void
 file_must_close(int fd)
 {
-    FileEntry *entry;
     dwrite_q *q = NULL;
-    if (fdstatGetType(fd) != FD_FILE)
-	fatal_dump("file_must_close: NOT A FILE");
-    entry = &file_table[fd];
-    if (entry->open_stat == FILE_NOT_OPEN)
-	return DISK_OK;
-    entry->close_request = REQUEST;
-    entry->write_daemon = NOT_PRESENT;
-    entry->write_pending = NO_WRT_PENDING;
+    FD_ENTRY *fde = &fd_table[fd];
+    if (fde->type != FD_FILE)
+	fatal_dump("file_must_close: type != FD_FILE");
+    if (!fde->open)
+	fatal_dump("file_must_close: FD not opened");
+    BIT_SET(fde->flags, FD_CLOSE_REQUEST);
+    BIT_RESET(fde->flags, FD_WRITE_DAEMON);
+    BIT_RESET(fde->flags, FD_WRITE_PENDING);
     /* Drain queue */
-    while (entry->write_q) {
-	q = entry->write_q;
-	entry->write_q = q->next;
+    while (fde->disk.write_q) {
+	q = fde->disk.write_q;
+	fde->disk.write_q = q->next;
 	if (q->free)
 	    (q->free) (q->buf);
 	safe_free(q);
     }
-    entry->write_q_tail = NULL;
-    if (entry->wrt_handle)
-	entry->wrt_handle(fd, DISK_ERROR, entry->wrt_handle_data);
+    fde->disk.write_q_tail = NULL;
+    if (fde->disk.wrt_handle)
+	fde->disk.wrt_handle(fd, DISK_ERROR, fde->disk.wrt_handle_data);
     commSetSelect(fd, COMM_SELECT_READ, NULL, NULL, 0);
     commSetSelect(fd, COMM_SELECT_WRITE, NULL, NULL, 0);
     file_close(fd);
-    return DISK_OK;
 }
 
 void
-file_open_fd(int fd, const char *name, File_Desc_Type type)
+file_open_fd(int fd, const char *name, unsigned int type)
 {
-    FileEntry *f = &file_table[fd];
+    FD_ENTRY *fde = &fd_table[fd];
+    if (fde->open)
+	fatal_dump("file_open_fd: already open");
+    memset(fde, '\0', sizeof(FD_ENTRY));
     fdstat_open(fd, type);
     commSetCloseOnExec(fd);
-    xstrncpy(f->filename, name, SQUID_MAXPATHLEN);
-    f->at_eof = NO;
-    f->open_stat = FILE_OPEN;
-    f->close_request = NOT_REQUEST;
-    f->write_pending = NO_WRT_PENDING;
-    f->write_daemon = NOT_PRESENT;
-    f->write_q = NULL;
-    memset(&fd_table[fd], '\0', sizeof(FD_ENTRY));
+    xstrncpy(fde->disk.filename, name, SQUID_MAXPATHLEN);
 }
 
 
 /* close a disk file. */
-int
+void
 file_close(int fd)
 {
-    FD_ENTRY *conn = NULL;
-    if (fd < 0) {
-	debug_trap("file_close: bad file number");
-	return DISK_ERROR;
+    FD_ENTRY *fde = NULL;
+    if (fd < 0)
+	fatal_dump("file_close: bad file number");
+    fde = &fd_table[fd];
+    if (!fde->open)
+	fatal_dump("file_close: already closed");
+    if (fde->type != FD_FILE)
+	fatal_dump("file_close: called for non-FILE");
+    if (BIT_TEST(fde->flags, FD_WRITE_DAEMON)) {
+	BIT_SET(fde->flags, FD_CLOSE_REQUEST);
+	return;
     }
-    /* we might have to flush all the write back queue before we can
-     * close it */
-    /* save it for later */
-
-    if (file_table[fd].open_stat == FILE_NOT_OPEN) {
-	debug(6, 3, "file_close: FD %d is not OPEN\n", fd);
-    } else if (file_table[fd].write_daemon == PRESENT) {
-	debug(6, 3, "file_close: FD %d has a write daemon PRESENT\n", fd);
-    } else if (file_table[fd].write_pending == WRT_PENDING) {
-	debug(6, 3, "file_close: FD %d has a write PENDING\n", fd);
-    } else {
-	file_table[fd].open_stat = FILE_NOT_OPEN;
-	file_table[fd].write_daemon = NOT_PRESENT;
-	file_table[fd].filename[0] = '\0';
-
-	if (fdstatGetType(fd) == FD_SOCKET) {
-	    debug(6, 0, "FD %d: Someone called file_close() on a socket\n", fd);
-	    fatal_dump(NULL);
-	}
-	/* update fdstat */
-	fdstat_close(fd);
-	conn = &fd_table[fd];
-	memset(conn, '\0', sizeof(FD_ENTRY));
-	comm_set_fd_lifetime(fd, -1);	/* invalidate the lifetime */
+    if (BIT_TEST(fde->flags, FD_WRITE_PENDING)) {
+	BIT_SET(fde->flags, FD_CLOSE_REQUEST);
+	return;
+    }
+    /* update fdstat */
+    fdstat_close(fd);
+    memset(fde, '\0', sizeof(FD_ENTRY));
+    comm_set_fd_lifetime(fd, -1);	/* invalidate the lifetime */
 #if USE_ASYNC_IO
-	aioClose(fd);
+    aioClose(fd);
 #else
-	close(fd);
+    close(fd);
 #endif
-	return DISK_OK;
-    }
-
-    /* refused to close file if there is a daemon running */
-    /* have pending flag set */
-    file_table[fd].close_request = REQUEST;
-    return DISK_ERROR;
 }
 
 
 /* write handler */
 static void
-diskHandleWrite(int fd, void *data)
+diskHandleWrite(int fd, void *unused)
 {
-    FileEntry *entry = data;
     int len = 0;
     disk_ctrl_t *ctrlp;
     dwrite_q *q = NULL;
     dwrite_q *wq = NULL;
-    if (!entry->write_q)
+    FD_ENTRY *fde = &fd_table[fd];
+    if (!fde->disk.write_q)
 	return;
-    if (file_table[fd].at_eof == NO)
+    if (!BIT_TEST(fde->flags, FD_AT_EOF))
 	lseek(fd, 0, SEEK_END);
     /* We need to combine subsequent write requests after the first */
-    if (entry->write_q->next != NULL && entry->write_q->next->next != NULL) {
-	for (len = 0, q = entry->write_q->next; q != NULL; q = q->next)
+    if (fde->disk.write_q->next != NULL && fde->disk.write_q->next->next != NULL) {
+	for (len = 0, q = fde->disk.write_q->next; q != NULL; q = q->next)
 	    len += q->len - q->cur_offset;
 	wq = xcalloc(1, sizeof(dwrite_q));
 	wq->buf = xmalloc(len);
