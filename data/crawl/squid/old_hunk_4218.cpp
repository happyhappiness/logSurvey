void
comm_write(int fd, const char *buf, int size, AsyncCall::Pointer &callback, FREE * free_func)
{
    assert(!fd_table[fd].flags.closing_);

    debugs(5, 5, "comm_write: FD " << fd << ": sz " << size << ": asynCall " << callback  << ".");

    if (commio_has_callback(fd, IOCB_WRITE, COMMIO_FD_WRITECB(fd))) {
        /* This means that the write has been scheduled, but has not
         * triggered yet 
         */
        fatalf ("comm_write: fd %d: pending callback!\n", fd);
    }

    commio_set_callback(fd, IOCB_WRITE, COMMIO_FD_WRITECB(fd),
        callback, (char *)buf, free_func, size);
    commSetSelect(fd, COMM_SELECT_WRITE, commHandleWrite, COMMIO_FD_WRITECB(fd), 0);
}


