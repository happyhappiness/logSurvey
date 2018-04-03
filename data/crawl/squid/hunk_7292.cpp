 	fatal_dump("diskHandleWriteComplete: offset > len");
     if (q->cur_offset == q->len) {
 	/* complete write */
-	entry->write_q = q->next;
+	fde->disk.write_q = q->next;
 	if (q->free)
 	    (q->free) (q->buf);
 	safe_free(q);
     }
-    if (entry->write_q != NULL) {
+    if (fde->disk.write_q != NULL) {
 	/* another block is queued */
 	commSetSelect(fd,
 	    COMM_SELECT_WRITE,
 	    diskHandleWrite,
-	    entry,
+	    NULL,
 	    0);
 	return DISK_OK;
     }
     /* no more data */
-    entry->write_q = entry->write_q_tail = NULL;
-    entry->write_pending = NO_WRT_PENDING;
-    entry->write_daemon = NOT_PRESENT;
-    if (entry->wrt_handle)
-	entry->wrt_handle(fd, DISK_OK, entry->wrt_handle_data);
-    if (file_table[fd].close_request == REQUEST)
+    fde->disk.write_q = fde->disk.write_q_tail = NULL;
+    BIT_RESET(fde->flags, FD_WRITE_PENDING);
+    BIT_RESET(fde->flags, FD_WRITE_DAEMON);
+    if (fde->disk.wrt_handle)
+	fde->disk.wrt_handle(fd, DISK_OK, fde->disk.wrt_handle_data);
+    if (BIT_TEST(fde->flags, FD_CLOSE_REQUEST))
 	file_close(fd);
     return DISK_OK;
 }
