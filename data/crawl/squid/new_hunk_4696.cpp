    clientUpdateSocketStats(http->logType, size);
    assert (this->fd() == fd);

    /* Bail out quickly on COMM_ERR_CLOSING - close handlers will tidy up */
    if (errflag == COMM_ERR_CLOSING)
        return;

    if (errflag || clientHttpRequestStatus(fd, http)) {
        initiateClose("failure or true request status");
        /* Do we leak here ? */
        return;
    }
