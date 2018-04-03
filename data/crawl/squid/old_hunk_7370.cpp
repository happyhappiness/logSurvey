static int
diskHandleWrite(int fd, FileEntry * entry)
{
    int rlen = 0;
    int len = 0;
    dwrite_q *r = NULL;
    if (file_table[fd].at_eof == NO)
	lseek(fd, 0, SEEK_END);
    while ((r = entry->write_q)) {
	debug(6, 3, "diskHandleWrite: FD %d, %d bytes\n", fd, r->len - r->cur_offset);
	len = write(fd, r->buf + r->cur_offset, r->len - r->cur_offset);
	file_table[fd].at_eof = YES;
	if (len < 0) {
	    if (errno == EAGAIN || errno == EWOULDBLOCK)
		break;
	    /* disk i/o failure--flushing all outstanding writes  */
	    debug(50, 1, "diskHandleWrite: FD %d: disk write error: %s\n",
		fd, xstrerror());
	    entry->write_daemon = NOT_PRESENT;
	    entry->write_pending = NO_WRT_PENDING;
	    /* call finish handler */
	    do {
		entry->write_q = r->next;
		if (r->free)
		    (r->free) (r->buf);
		safe_free(r);
	    } while ((r = entry->write_q));
	    if (entry->wrt_handle) {
		entry->wrt_handle(fd,
		    errno == ENOSPC ? DISK_NO_SPACE_LEFT : DISK_ERROR,
		    entry->wrt_handle_data);
	    }
	    return DISK_ERROR;
	}
	rlen += len;
	r->cur_offset += len;
	if (r->cur_offset < r->len)
	    continue;		/* partial write? */
	/* complete write */
	entry->write_q = r->next;
	if (r->free)
	    (r->free) (r->buf);
	safe_free(r);
    }
    if (entry->write_q == NULL) {
	/* no more data */
	entry->write_q_tail = NULL;
	entry->write_pending = NO_WRT_PENDING;
	entry->write_daemon = NOT_PRESENT;
    } else {
	commSetSelect(fd,
	    COMM_SELECT_WRITE,
	    (PF) diskHandleWrite,
	    (void *) entry,
	    0);
	entry->write_daemon = PRESENT;
    }
    if (entry->wrt_handle)
	entry->wrt_handle(fd, DISK_OK, entry->wrt_handle_data);
    if (file_table[fd].close_request == REQUEST)
