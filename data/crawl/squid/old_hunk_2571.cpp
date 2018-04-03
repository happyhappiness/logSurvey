        storeAppendPrintf(s, "Connection: %p\n", conn);

        if (conn != NULL) {
            fd = conn->fd;
            storeAppendPrintf(s, "\tFD %d, read %"PRId64", wrote %"PRId64"\n", fd,
                              fd_table[fd].bytes_read, fd_table[fd].bytes_written);
            storeAppendPrintf(s, "\tFD desc: %s\n", fd_table[fd].desc);
            storeAppendPrintf(s, "\tin: buf %p, offset %ld, size %ld\n",
                              conn->in.buf, (long int) conn->in.notYetUsed, (long int) conn->in.allocatedSize);
            storeAppendPrintf(s, "\tpeer: %s:%d\n",
                              conn->peer.NtoA(buf,MAX_IPSTRLEN),
                              conn->peer.GetPort());
            storeAppendPrintf(s, "\tme: %s:%d\n",
                              conn->me.NtoA(buf,MAX_IPSTRLEN),
                              conn->me.GetPort());
            storeAppendPrintf(s, "\tnrequests: %d\n",
                              conn->nrequests);
        }
