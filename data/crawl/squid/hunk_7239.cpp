     xfree(ctrlp);
 }
 
-/* must close a disk file */
-
-void
-file_must_close(int fd)
-{
-    dwrite_q *q = NULL;
-    FD_ENTRY *fde = &fd_table[fd];
-    if (fde->type != FD_FILE)
-	fatal_dump("file_must_close: type != FD_FILE");
-    if (!fde->open)
-	fatal_dump("file_must_close: FD not opened");
-    BIT_SET(fde->flags, FD_CLOSE_REQUEST);
-    BIT_RESET(fde->flags, FD_WRITE_DAEMON);
-    BIT_RESET(fde->flags, FD_WRITE_PENDING);
-    /* Drain queue */
-    while (fde->disk.write_q) {
-	q = fde->disk.write_q;
-	fde->disk.write_q = q->next;
-	if (q->free)
-	    (q->free) (q->buf);
-	safe_free(q);
-    }
-    fde->disk.write_q_tail = NULL;
-    if (fde->disk.wrt_handle)
-	fde->disk.wrt_handle(fd, DISK_ERROR, fde->disk.wrt_handle_data);
-    commSetSelect(fd, COMM_SELECT_READ, NULL, NULL, 0);
-    commSetSelect(fd, COMM_SELECT_WRITE, NULL, NULL, 0);
-    file_close(fd);
-}
-
 /* close a disk file. */
 void
 file_close(int fd)
