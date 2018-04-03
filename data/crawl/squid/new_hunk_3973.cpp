        fatal("Aiee! out of aiocb slots FIXME and wrap file_write !\n");
        debugs(79, 1, "WARNING: out of aiocb slots!");
        /* fall back to blocking method */
        //        file_write(fd, offset, unsafeBuf, len, callback, data, freefunc);
        return;
    }

