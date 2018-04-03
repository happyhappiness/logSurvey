
        if (conn != NULL) {
            fd = conn->fd;
            storeAppendPrintf(s, "\tFD %d, read %d, wrote %d\n", fd,
                              fd_table[fd].bytes_read, fd_table[fd].bytes_written);
            storeAppendPrintf(s, "\tFD desc: %s\n", fd_table[fd].desc);
            storeAppendPrintf(s, "\tin: buf %p, offset %ld, size %ld\n",
