        fatalf("Aiee! aio_write() returned error (%d) FIXME and wrap file_write !\n", errno);
        debugs(79, 1, "WARNING: aio_write() returned error: " << xstrerror());
        /* fall back to blocking method */
        //       file_write(fd, offset, buf, len, callback, data, freefunc);
    }
}

