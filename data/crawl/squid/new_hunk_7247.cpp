	wq->next = NULL;
	wq->free = xfree;
	do {
	    q = fdd->write_q->next;
	    len = q->len - q->cur_offset;
	    xmemcpy(wq->buf + wq->len, q->buf + q->cur_offset, len);
	    wq->len += len;
	    fdd->write_q->next = q->next;
	    if (q->free)
		(q->free) (q->buf);
	    safe_free(q);
	} while (fdd->write_q->next != NULL);
	fdd->write_q_tail = wq;
	fdd->write_q->next = wq;
    }
    ctrlp = xcalloc(1, sizeof(disk_ctrl_t));
    ctrlp->fd = fd;
#if USE_ASYNC_IO
    aioWrite(fd,
	fdd->write_q->buf + fdd->write_q->cur_offset,
	fdd->write_q->len - fdd->write_q->cur_offset,
	diskHandleWriteComplete,
	ctrlp);
#else
    len = write(fd,
	fdd->write_q->buf + fdd->write_q->cur_offset,
	fdd->write_q->len - fdd->write_q->cur_offset);
    diskHandleWriteComplete(ctrlp, len, errno);
#endif
}

static void
diskHandleWriteComplete(void *data, int len, int errcode)
{
    disk_ctrl_t *ctrlp = data;
    int fd = ctrlp->fd;
    FD_ENTRY *fde = &fd_table[fd];
    struct _fde_disk *fdd = &fde->disk;
    dwrite_q *q = fdd->write_q;
    int status = DISK_OK;
    errno = errcode;
    safe_free(data);
    fd_bytes(fd, len, FD_WRITE);
    if (q == NULL)		/* Someone aborted then write completed */
	return;
    if (len < 0) {
	if (errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR) {
	    (void) 0;
	} else {
	    status = errno == ENOSPC ? DISK_NO_SPACE_LEFT : DISK_ERROR;
	    debug(50, 1, "diskHandleWrite: FD %d: disk write error: %s\n",
		fd, xstrerror());
	    if (fdd->wrt_handle == NULL) {
		/* FLUSH PENDING BUFFERS */
		do {
		    fdd->write_q = q->next;
		    if (q->free)
			(q->free) (q->buf);
		    safe_free(q);
		} while ((q = fdd->write_q));
	    }
	}
	len = 0;
    }
    q->cur_offset += len;
    assert(q->cur_offset <= q->len);
    if (q->cur_offset == q->len) {
	/* complete write */
	fdd->write_q = q->next;
	if (q->free)
	    (q->free) (q->buf);
	safe_free(q);
    }
    if (fdd->write_q == NULL) {
	/* no more data */
	fdd->write_q_tail = NULL;
	BIT_RESET(fde->flags, FD_WRITE_PENDING);
	BIT_RESET(fde->flags, FD_WRITE_DAEMON);
    } else {
	/* another block is queued */
	commSetSelect(fd, COMM_SELECT_WRITE, diskHandleWrite, NULL, 0);
	BIT_SET(fde->flags, FD_WRITE_DAEMON);
    }
    if (fdd->wrt_handle)
	fdd->wrt_handle(fd, status, fdd->wrt_handle_data);
    if (BIT_TEST(fde->flags, FD_CLOSE_REQUEST))
	file_close(fd);
}


