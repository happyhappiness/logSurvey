	wq->next = NULL;
	wq->free = xfree;
	do {
	    q = fde->disk.write_q->next;
	    len = q->len - q->cur_offset;
	    memcpy(wq->buf + wq->len, q->buf + q->cur_offset, len);
	    wq->len += len;
	    fde->disk.write_q->next = q->next;
	    if (q->free)
		(q->free) (q->buf);
	    safe_free(q);
	} while (fde->disk.write_q->next != NULL);
	fde->disk.write_q_tail = wq;
	fde->disk.write_q->next = wq;
    }
    ctrlp = xcalloc(1, sizeof(disk_ctrl_t));
    ctrlp->fd = fd;
#if USE_ASYNC_IO
    aioWrite(fd,
	fde->disk.write_q->buf + fde->disk.write_q->cur_offset,
	fde->disk.write_q->len - fde->disk.write_q->cur_offset,
	diskHandleWriteComplete,
	ctrlp);
#else
    len = write(fd,
	fde->disk.write_q->buf + fde->disk.write_q->cur_offset,
	fde->disk.write_q->len - fde->disk.write_q->cur_offset);
    diskHandleWriteComplete(ctrlp, len, errno);
#endif
}

static int
diskHandleWriteComplete(void *data, int len, int errcode)
{
    disk_ctrl_t *ctrlp = data;
    int fd = ctrlp->fd;
    FD_ENTRY *fde = &fd_table[fd];
    dwrite_q *q = fde->disk.write_q;
    errno = errcode;
    safe_free(data);
    fd_bytes(fd, len, FD_WRITE);
    if (q == NULL)		/* Someone aborted and then the write */
	return DISK_ERROR;	/* completed anyway. :( */
    BIT_SET(fde->flags, FD_AT_EOF);
    if (len < 0) {
	if (errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR) {
	    len = 0;
	} else {
	    /* disk i/o failure--flushing all outstanding writes  */
	    debug(50, 1, "diskHandleWrite: FD %d: disk write error: %s\n",
		fd, xstrerror());
	    BIT_RESET(fde->flags, FD_WRITE_DAEMON);
	    BIT_RESET(fde->flags, FD_WRITE_PENDING);
	    /* call finish handler */
	    do {
		fde->disk.write_q = q->next;
		if (q->free)
		    (q->free) (q->buf);
		safe_free(q);
	    } while ((q = fde->disk.write_q));
	    if (fde->disk.wrt_handle) {
		fde->disk.wrt_handle(fd,
		    errno == ENOSPC ? DISK_NO_SPACE_LEFT : DISK_ERROR,
		    fde->disk.wrt_handle_data);
	    }
	    return DISK_ERROR;
	}
    }
    q->cur_offset += len;
    if (q->cur_offset > q->len)
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


