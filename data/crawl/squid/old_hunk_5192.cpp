    debug(33, 5) ("clientWriteComplete: FD %d, sz %ld, err %d, off %ld, len %d\n",
                  fd, (long int) size, errflag, (long int) http->out.size, entry ? objectLen(entry) : 0);
    clientUpdateSocketStats(http->logType, size);

    if (errflag || clientHttpRequestStatus(fd, http)) {
        debug (33,5)("clientWriteComplete: FD %d, closing connection due to failure, or true requeststatus\n", fd);
        comm_close(fd);
        /* Do we leak here ? */
        return;
    }