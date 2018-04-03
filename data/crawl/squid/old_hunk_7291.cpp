
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

void
file_open_fd(int fd, const char *name, File_Desc_Type type)
{
    FileEntry *f = &file_table[fd];
    fdstat_open(fd, type);
    commSetCloseOnExec(fd);
    xstrncpy(f->filename, name, SQUID_MAXPATHLEN);
    f->at_eof = NO;
    f->open_stat = FILE_OPEN;
    f->close_request = NOT_REQUEST;
    f->write_pending = NO_WRT_PENDING;
    f->write_daemon = NOT_PRESENT;
    f->write_q = NULL;
    memset(&fd_table[fd], '\0', sizeof(FD_ENTRY));
}


/* close a disk file. */
int
file_close(int fd)
{
    FD_ENTRY *conn = NULL;
    if (fd < 0) {
	debug_trap("file_close: bad file number");
	return DISK_ERROR;
    }
    /* we might have to flush all the write back queue before we can
     * close it */
    /* save it for later */

    if (file_table[fd].open_stat == FILE_NOT_OPEN) {
	debug(6, 3, "file_close: FD %d is not OPEN\n", fd);
    } else if (file_table[fd].write_daemon == PRESENT) {
	debug(6, 3, "file_close: FD %d has a write daemon PRESENT\n", fd);
    } else if (file_table[fd].write_pending == WRT_PENDING) {
	debug(6, 3, "file_close: FD %d has a write PENDING\n", fd);
    } else {
	file_table[fd].open_stat = FILE_NOT_OPEN;
	file_table[fd].write_daemon = NOT_PRESENT;
	file_table[fd].filename[0] = '\0';

	if (fdstatGetType(fd) == FD_SOCKET) {
	    debug(6, 0, "FD %d: Someone called file_close() on a socket\n", fd);
	    fatal_dump(NULL);
	}
	/* update fdstat */
	fdstat_close(fd);
	conn = &fd_table[fd];
	memset(conn, '\0', sizeof(FD_ENTRY));
	comm_set_fd_lifetime(fd, -1);	/* invalidate the lifetime */
#if USE_ASYNC_IO
	aioClose(fd);
#else
	close(fd);
#endif
	return DISK_OK;
    }

    /* refused to close file if there is a daemon running */
    /* have pending flag set */
    file_table[fd].close_request = REQUEST;
    return DISK_ERROR;
}


/* write handler */
static void
diskHandleWrite(int fd, void *data)
{
    FileEntry *entry = data;
    int len = 0;
    disk_ctrl_t *ctrlp;
    dwrite_q *q = NULL;
    dwrite_q *wq = NULL;
    if (!entry->write_q)
	return;
    if (file_table[fd].at_eof == NO)
	lseek(fd, 0, SEEK_END);
    /* We need to combine subsequent write requests after the first */
    if (entry->write_q->next != NULL && entry->write_q->next->next != NULL) {
	for (len = 0, q = entry->write_q->next; q != NULL; q = q->next)
	    len += q->len - q->cur_offset;
	wq = xcalloc(1, sizeof(dwrite_q));
	wq->buf = xmalloc(len);
