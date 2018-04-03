 /* Exported routines */
 
 void
-a_file_read(async_queue_t *q, int fd, void *buf, int req_len, off_t offset,
-  DRCB *callback, void *data)
+a_file_read(async_queue_t * q, int fd, void *buf, int req_len, off_t offset,
+    DRCB * callback, void *data)
 {
-	int slot;
-	async_queue_entry_t *qe;
+    int slot;
+    async_queue_entry_t *qe;
 
-	assert(q->aq_state == AQ_STATE_SETUP);
+    assert(q->aq_state == AQ_STATE_SETUP);
 
 #if 0
-	file_read(fd, buf, req_len, offset, callback, data);
+    file_read(fd, buf, req_len, offset, callback, data);
 #endif
-	/* Find a free slot */
-	slot = a_file_findslot(q);
-	if (slot < 0) {
-		/* No free slot? Callback error, and return */
-		fatal("Aiee! out of aiocb slots!\n");
-	}
-
-	/* Mark slot as ours */
-	qe = &q->aq_queue[slot];
-	qe->aq_e_state = AQ_ENTRY_USED;
-	qe->aq_e_callback.read = callback;
-	qe->aq_e_callback_data = data;
-	qe->aq_e_type = AQ_ENTRY_READ;
-	qe->aq_e_free = NULL;
-	qe->aq_e_buf = buf;
-	qe->aq_e_fd = fd;
-
-	qe->aq_e_aiocb.aio_fildes = fd;
-	qe->aq_e_aiocb.aio_nbytes = req_len;
-	qe->aq_e_aiocb.aio_offset = offset;
-	qe->aq_e_aiocb.aio_buf = buf;
-
-	/* Account */
-	q->aq_numpending++;
-
-	/* Lock */
-	cbdataLock(data);
-
-	/* Initiate aio */
-	if (aio_read(&qe->aq_e_aiocb) < 0) {
-		debug(1, 1)("Aiee! aio_read() returned error (%d)!\n", errno);
-		assert(1==0);
-	}
+    /* Find a free slot */
+    slot = a_file_findslot(q);
+    if (slot < 0) {
+	/* No free slot? Callback error, and return */
+	fatal("Aiee! out of aiocb slots!\n");
+    }
+    /* Mark slot as ours */
+    qe = &q->aq_queue[slot];
+    qe->aq_e_state = AQ_ENTRY_USED;
+    qe->aq_e_callback.read = callback;
+    qe->aq_e_callback_data = data;
+    qe->aq_e_type = AQ_ENTRY_READ;
+    qe->aq_e_free = NULL;
+    qe->aq_e_buf = buf;
+    qe->aq_e_fd = fd;
+
+    qe->aq_e_aiocb.aio_fildes = fd;
+    qe->aq_e_aiocb.aio_nbytes = req_len;
+    qe->aq_e_aiocb.aio_offset = offset;
+    qe->aq_e_aiocb.aio_buf = buf;
+
+    /* Account */
+    q->aq_numpending++;
+
+    /* Lock */
+    cbdataLock(data);
+
+    /* Initiate aio */
+    if (aio_read(&qe->aq_e_aiocb) < 0) {
+	debug(1, 1) ("Aiee! aio_read() returned error (%d)!\n", errno);
+	assert(1 == 0);
+    }
 }
 
 
 void
-a_file_write(async_queue_t *q, int fd, off_t offset, void *buf, int len,
-  DWCB *callback, void *data, FREE *freefunc)
+a_file_write(async_queue_t * q, int fd, off_t offset, void *buf, int len,
+    DWCB * callback, void *data, FREE * freefunc)
 {
-	int slot;
-	async_queue_entry_t *qe;
+    int slot;
+    async_queue_entry_t *qe;
 
-	assert(q->aq_state == AQ_STATE_SETUP);
+    assert(q->aq_state == AQ_STATE_SETUP);
 
 #if 0
-	file_write(fd, offset, buf, len, callback, data, freefunc);
+    file_write(fd, offset, buf, len, callback, data, freefunc);
 #endif
-	/* Find a free slot */
-	slot = a_file_findslot(q);
-	if (slot < 0) {
-		/* No free slot? Callback error, and return */
-		fatal("Aiee! out of aiocb slots!\n");
-	}
-
-	/* Mark slot as ours */
-	qe = &q->aq_queue[slot];
-	qe->aq_e_state = AQ_ENTRY_USED;
-	qe->aq_e_callback.write = callback;
-	qe->aq_e_callback_data = data;
-	qe->aq_e_type = AQ_ENTRY_WRITE;
-	qe->aq_e_free = freefunc;
-	qe->aq_e_buf = buf;
-	qe->aq_e_fd = fd;
-
-	qe->aq_e_aiocb.aio_fildes = fd;
-	qe->aq_e_aiocb.aio_nbytes = len;
-	qe->aq_e_aiocb.aio_offset = offset;
-	qe->aq_e_aiocb.aio_buf = buf;
-
-	/* Account */
-	q->aq_numpending++;
-
-	/* Lock */
-	cbdataLock(data);
-
-	/* Initiate aio */
-	if (aio_write(&qe->aq_e_aiocb) < 0) {
-		debug(1, 1)("Aiee! aio_read() returned error (%d)!\n", errno);
-		assert(1==0);
-	}
+    /* Find a free slot */
+    slot = a_file_findslot(q);
+    if (slot < 0) {
+	/* No free slot? Callback error, and return */
+	fatal("Aiee! out of aiocb slots!\n");
+    }
+    /* Mark slot as ours */
+    qe = &q->aq_queue[slot];
+    qe->aq_e_state = AQ_ENTRY_USED;
+    qe->aq_e_callback.write = callback;
+    qe->aq_e_callback_data = data;
+    qe->aq_e_type = AQ_ENTRY_WRITE;
+    qe->aq_e_free = freefunc;
+    qe->aq_e_buf = buf;
+    qe->aq_e_fd = fd;
+
+    qe->aq_e_aiocb.aio_fildes = fd;
+    qe->aq_e_aiocb.aio_nbytes = len;
+    qe->aq_e_aiocb.aio_offset = offset;
+    qe->aq_e_aiocb.aio_buf = buf;
+
+    /* Account */
+    q->aq_numpending++;
+
+    /* Lock */
+    cbdataLock(data);
+
+    /* Initiate aio */
+    if (aio_write(&qe->aq_e_aiocb) < 0) {
+	debug(1, 1) ("Aiee! aio_read() returned error (%d)!\n", errno);
+	assert(1 == 0);
+    }
 }
 
 
