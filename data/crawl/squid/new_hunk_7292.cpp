	fatal_dump("diskHandleWriteComplete: offset > len");
    if (q->cur_offset == q->len) {
	/* complete write */
	fde->disk.write_q = q->next;
	if (q->free)
	    (q->free) (q->buf);
	safe_free(q);
    }
    if (fde->disk.write_q != NULL) {
	/* another block is queued */
	commSetSelect(fd,
	    COMM_SELECT_WRITE,
	    diskHandleWrite,
	    NULL,
	    0);
	return DISK_OK;
    }
    /* no more data */
    fde->disk.write_q = fde->disk.write_q_tail = NULL;
    BIT_RESET(fde->flags, FD_WRITE_PENDING);
    BIT_RESET(fde->flags, FD_WRITE_DAEMON);
    if (fde->disk.wrt_handle)
	fde->disk.wrt_handle(fd, DISK_OK, fde->disk.wrt_handle_data);
    if (BIT_TEST(fde->flags, FD_CLOSE_REQUEST))
	file_close(fd);
    return DISK_OK;
}
