	fatal_dump("comm_close: not a SOCKET");
    fde->open = 0;
    RWStateCallbackAndFree(fd, COMM_ERROR);
    commCallCloseHandlers(fd);
    fd_close(fd);		/* update fdstat */
#if USE_ASYNC_IO
    aioClose(fd);
#else
    close(fd);
#endif
}
