    clientUpdateSocketStats(http->logType, size);
    assert (this->fd() == fd);

    if (errflag || clientHttpRequestStatus(fd, http)) {
        debug (33,5)("clientWriteComplete: FD %d, closing connection due to failure, or true requeststatus\n", fd);
        initiateClose();
        /* Do we leak here ? */
        return;
    }
