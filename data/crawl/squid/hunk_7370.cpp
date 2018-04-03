 static int
 diskHandleWrite(int fd, FileEntry * entry)
 {
-    int rlen = 0;
     int len = 0;
-    dwrite_q *r = NULL;
+    disk_ctrl_t *ctrlp;
+    dwrite_q *q = NULL;
+    dwrite_q *wq = NULL;
+    if (!entry->write_q)
+	return DISK_OK;
     if (file_table[fd].at_eof == NO)
 	lseek(fd, 0, SEEK_END);
-    while ((r = entry->write_q)) {
-	debug(6, 3, "diskHandleWrite: FD %d, %d bytes\n", fd, r->len - r->cur_offset);
-	len = write(fd, r->buf + r->cur_offset, r->len - r->cur_offset);
-	file_table[fd].at_eof = YES;
-	if (len < 0) {
-	    if (errno == EAGAIN || errno == EWOULDBLOCK)
-		break;
+    /* We need to combine subsequent write requests after the first */
+    if (entry->write_q->next != NULL && entry->write_q->next->next != NULL) {
+	for (len = 0, q = entry->write_q->next; q != NULL; q = q->next)
+	    len += q->len - q->cur_offset;
+	wq = xcalloc(1, sizeof(dwrite_q));
+	wq->buf = xmalloc(len);
+	wq->len = 0;
+	wq->cur_offset = 0;
+	wq->next = NULL;
+	wq->free = xfree;
+	do {
+	    q = entry->write_q->next;
+	    len = q->len - q->cur_offset;
+	    memcpy(wq->buf + wq->len, q->buf + q->cur_offset, len);
+	    wq->len += len;
+	    entry->write_q->next = q->next;
+	    if (q->free)
+		(q->free) (q->buf);
+	    safe_free(q);
+	} while (entry->write_q->next != NULL);
+	entry->write_q_tail = wq;
+	entry->write_q->next = wq;
+    }
+    ctrlp = xcalloc(1, sizeof(disk_ctrl_t));
+    ctrlp->fd = fd;
+    ctrlp->data = (void *) entry;
+#if USE_ASYNC_IO
+    aioWrite(fd,
+	entry->write_q->buf + entry->write_q->cur_offset,
+	entry->write_q->len - entry->write_q->cur_offset,
+	diskHandleWriteComplete,
+	(void *) ctrlp);
+    return DISK_OK;
+#else
+    len = write(fd,
+	entry->write_q->buf + entry->write_q->cur_offset,
+	entry->write_q->len - entry->write_q->cur_offset);
+    return diskHandleWriteComplete(ctrlp, len, errno);
+#endif
+}
+
+static int
+diskHandleWriteComplete(void *data, int retcode, int errcode)
+{
+    disk_ctrl_t *ctrlp = data;
+    FileEntry *entry = ctrlp->data;
+    dwrite_q *q = entry->write_q;
+    int fd = ctrlp->fd;
+    int len = retcode;
+    errno = errcode;
+    safe_free(data);
+    if (q == NULL)		/* Someone aborted and then the write */
+	return DISK_ERROR;	/* completed anyway. :( */
+    file_table[fd].at_eof = YES;
+    if (len < 0) {
+	if (errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR) {
+	    len = 0;
+	} else {
 	    /* disk i/o failure--flushing all outstanding writes  */
 	    debug(50, 1, "diskHandleWrite: FD %d: disk write error: %s\n",
 		fd, xstrerror());
 	    entry->write_daemon = NOT_PRESENT;
 	    entry->write_pending = NO_WRT_PENDING;
 	    /* call finish handler */
 	    do {
-		entry->write_q = r->next;
-		if (r->free)
-		    (r->free) (r->buf);
-		safe_free(r);
-	    } while ((r = entry->write_q));
+		entry->write_q = q->next;
+		if (q->free)
+		    (q->free) (q->buf);
+		safe_free(q);
+	    } while ((q = entry->write_q));
 	    if (entry->wrt_handle) {
 		entry->wrt_handle(fd,
 		    errno == ENOSPC ? DISK_NO_SPACE_LEFT : DISK_ERROR,
 		    entry->wrt_handle_data);
 	    }
 	    return DISK_ERROR;
 	}
-	rlen += len;
-	r->cur_offset += len;
-	if (r->cur_offset < r->len)
-	    continue;		/* partial write? */
+    }
+    q->cur_offset += len;
+    if (q->cur_offset > q->len)
+	fatal_dump("diskHandleWriteComplete: offset > len");
+    if (q->cur_offset == q->len) {
 	/* complete write */
-	entry->write_q = r->next;
-	if (r->free)
-	    (r->free) (r->buf);
-	safe_free(r);
+	entry->write_q = q->next;
+	if (q->free)
+	    (q->free) (q->buf);
+	safe_free(q);
     }
-    if (entry->write_q == NULL) {
-	/* no more data */
-	entry->write_q_tail = NULL;
-	entry->write_pending = NO_WRT_PENDING;
-	entry->write_daemon = NOT_PRESENT;
-    } else {
+    if (entry->write_q != NULL) {
+	/* another block is queued */
 	commSetSelect(fd,
 	    COMM_SELECT_WRITE,
 	    (PF) diskHandleWrite,
 	    (void *) entry,
 	    0);
-	entry->write_daemon = PRESENT;
+	return DISK_OK;
     }
+    /* no more data */
+    entry->write_q = entry->write_q_tail = NULL;
+    entry->write_pending = NO_WRT_PENDING;
+    entry->write_daemon = NOT_PRESENT;
     if (entry->wrt_handle)
 	entry->wrt_handle(fd, DISK_OK, entry->wrt_handle_data);
     if (file_table[fd].close_request == REQUEST)
