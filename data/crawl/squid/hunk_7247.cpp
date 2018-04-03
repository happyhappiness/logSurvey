 	wq->next = NULL;
 	wq->free = xfree;
 	do {
-	    q = fde->disk.write_q->next;
+	    q = fdd->write_q->next;
 	    len = q->len - q->cur_offset;
-	    memcpy(wq->buf + wq->len, q->buf + q->cur_offset, len);
+	    xmemcpy(wq->buf + wq->len, q->buf + q->cur_offset, len);
 	    wq->len += len;
-	    fde->disk.write_q->next = q->next;
+	    fdd->write_q->next = q->next;
 	    if (q->free)
 		(q->free) (q->buf);
 	    safe_free(q);
-	} while (fde->disk.write_q->next != NULL);
-	fde->disk.write_q_tail = wq;
-	fde->disk.write_q->next = wq;
+	} while (fdd->write_q->next != NULL);
+	fdd->write_q_tail = wq;
+	fdd->write_q->next = wq;
     }
     ctrlp = xcalloc(1, sizeof(disk_ctrl_t));
     ctrlp->fd = fd;
 #if USE_ASYNC_IO
     aioWrite(fd,
-	fde->disk.write_q->buf + fde->disk.write_q->cur_offset,
-	fde->disk.write_q->len - fde->disk.write_q->cur_offset,
+	fdd->write_q->buf + fdd->write_q->cur_offset,
+	fdd->write_q->len - fdd->write_q->cur_offset,
 	diskHandleWriteComplete,
 	ctrlp);
 #else
     len = write(fd,
-	fde->disk.write_q->buf + fde->disk.write_q->cur_offset,
-	fde->disk.write_q->len - fde->disk.write_q->cur_offset);
+	fdd->write_q->buf + fdd->write_q->cur_offset,
+	fdd->write_q->len - fdd->write_q->cur_offset);
     diskHandleWriteComplete(ctrlp, len, errno);
 #endif
 }
 
-static int
+static void
 diskHandleWriteComplete(void *data, int len, int errcode)
 {
     disk_ctrl_t *ctrlp = data;
     int fd = ctrlp->fd;
     FD_ENTRY *fde = &fd_table[fd];
-    dwrite_q *q = fde->disk.write_q;
+    struct _fde_disk *fdd = &fde->disk;
+    dwrite_q *q = fdd->write_q;
+    int status = DISK_OK;
     errno = errcode;
     safe_free(data);
     fd_bytes(fd, len, FD_WRITE);
-    if (q == NULL)		/* Someone aborted and then the write */
-	return DISK_ERROR;	/* completed anyway. :( */
-    BIT_SET(fde->flags, FD_AT_EOF);
+    if (q == NULL)		/* Someone aborted then write completed */
+	return;
     if (len < 0) {
 	if (errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR) {
-	    len = 0;
+	    (void) 0;
 	} else {
-	    /* disk i/o failure--flushing all outstanding writes  */
+	    status = errno == ENOSPC ? DISK_NO_SPACE_LEFT : DISK_ERROR;
 	    debug(50, 1, "diskHandleWrite: FD %d: disk write error: %s\n",
 		fd, xstrerror());
-	    BIT_RESET(fde->flags, FD_WRITE_DAEMON);
-	    BIT_RESET(fde->flags, FD_WRITE_PENDING);
-	    /* call finish handler */
-	    do {
-		fde->disk.write_q = q->next;
-		if (q->free)
-		    (q->free) (q->buf);
-		safe_free(q);
-	    } while ((q = fde->disk.write_q));
-	    if (fde->disk.wrt_handle) {
-		fde->disk.wrt_handle(fd,
-		    errno == ENOSPC ? DISK_NO_SPACE_LEFT : DISK_ERROR,
-		    fde->disk.wrt_handle_data);
+	    if (fdd->wrt_handle == NULL) {
+		/* FLUSH PENDING BUFFERS */
+		do {
+		    fdd->write_q = q->next;
+		    if (q->free)
+			(q->free) (q->buf);
+		    safe_free(q);
+		} while ((q = fdd->write_q));
 	    }
-	    return DISK_ERROR;
 	}
+	len = 0;
     }
     q->cur_offset += len;
-    if (q->cur_offset > q->len)
-	fatal_dump("diskHandleWriteComplete: offset > len");
+    assert(q->cur_offset <= q->len);
     if (q->cur_offset == q->len) {
 	/* complete write */
-	fde->disk.write_q = q->next;
+	fdd->write_q = q->next;
 	if (q->free)
 	    (q->free) (q->buf);
 	safe_free(q);
     }
-    if (fde->disk.write_q != NULL) {
+    if (fdd->write_q == NULL) {
+	/* no more data */
+	fdd->write_q_tail = NULL;
+	BIT_RESET(fde->flags, FD_WRITE_PENDING);
+	BIT_RESET(fde->flags, FD_WRITE_DAEMON);
+    } else {
 	/* another block is queued */
-	commSetSelect(fd,
-	    COMM_SELECT_WRITE,
-	    diskHandleWrite,
-	    NULL,
-	    0);
-	return DISK_OK;
+	commSetSelect(fd, COMM_SELECT_WRITE, diskHandleWrite, NULL, 0);
+	BIT_SET(fde->flags, FD_WRITE_DAEMON);
     }
-    /* no more data */
-    fde->disk.write_q = fde->disk.write_q_tail = NULL;
-    BIT_RESET(fde->flags, FD_WRITE_PENDING);
-    BIT_RESET(fde->flags, FD_WRITE_DAEMON);
-    if (fde->disk.wrt_handle)
-	fde->disk.wrt_handle(fd, DISK_OK, fde->disk.wrt_handle_data);
+    if (fdd->wrt_handle)
+	fdd->wrt_handle(fd, status, fdd->wrt_handle_data);
     if (BIT_TEST(fde->flags, FD_CLOSE_REQUEST))
 	file_close(fd);
-    return DISK_OK;
 }
 
 
