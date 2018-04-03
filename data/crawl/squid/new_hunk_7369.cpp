
    conn = &fd_table[fd];
    memset(conn, '\0', sizeof(FD_ENTRY));
    if (ctrlp->callback)
	(ctrlp->callback) (ctrlp->callback_data, fd);
    xfree(ctrlp->path);
    xfree(ctrlp);
}


/* must close a disk file */

int
file_must_close(int fd)
{
    FileEntry *entry;
    dwrite_q *q = NULL;
    if (fdstatGetType(fd) != FD_FILE)
	fatal_dump("file_must_close: NOT A FILE");
    entry = &file_table[fd];
    if (entry->open_stat == FILE_NOT_OPEN)
	return DISK_OK;
    entry->close_request = REQUEST;
    entry->write_daemon = NOT_PRESENT;
    entry->write_pending = NO_WRT_PENDING;
    /* Drain queue */
    while (entry->write_q) {
	q = entry->write_q;
	entry->write_q = q->next;
	if (q->free)
	    (q->free) (q->buf);
	safe_free(q);
    }
    entry->write_q_tail = NULL;
    if (entry->wrt_handle)
	entry->wrt_handle(fd, DISK_ERROR, entry->wrt_handle_data);
    commSetSelect(fd, COMM_SELECT_READ, NULL, NULL, 0);
    commSetSelect(fd, COMM_SELECT_WRITE, NULL, NULL, 0);
    file_close(fd);
    return DISK_OK;
}


