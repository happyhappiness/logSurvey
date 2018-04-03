        packerClean(&p);
    }

    memBufPrintf(&mb, "\r\n");
    debug(24, 6) ("waisSendRequest: buf: %s\n", mb.buf);
    comm_old_write_mbuf(fd, &mb, waisSendComplete, waisState);
