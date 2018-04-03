	fatal_dump("diskHandleWriteComplete: offset > len");
    if (q->cur_offset == q->len) {
	/* complete write */
	entry->write_q = q->next;
	if (q->free)
	    (q->free) (q->buf);
	safe_free(q);
    }
    if (entry->write_q != NULL) {
	/* another block is queued */
	commSetSelect(fd,
	    COMM_SELECT_WRITE,
	    diskHandleWrite,
	    entry,
	    0);
	return DISK_OK;
    }
    /* no more data */
    entry->write_q = entry->write_q_tail = NULL;
    entry->write_pending = NO_WRT_PENDING;
    entry->write_daemon = NOT_PRESENT;
    if (entry->wrt_handle)
	entry->wrt_handle(fd, DISK_OK, entry->wrt_handle_data);
    if (file_table[fd].close_request == REQUEST)
	file_close(fd);
    return DISK_OK;
}
