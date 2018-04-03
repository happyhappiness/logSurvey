            storeAppendPrintf(s, "\tin: buf %p, offset %ld, size %ld\n",
                              conn->in.buf, (long int) conn->in.notYetUsed, (long int) conn->in.allocatedSize);
            storeAppendPrintf(s, "\tpeer: %s:%d\n",
                              inet_ntoa(conn->peer.sin_addr),
                              ntohs(conn->peer.sin_port));
            storeAppendPrintf(s, "\tme: %s:%d\n",
                              inet_ntoa(conn->me.sin_addr),
                              ntohs(conn->me.sin_port));
            storeAppendPrintf(s, "\tnrequests: %d\n",
                              conn->nrequests);
        }
