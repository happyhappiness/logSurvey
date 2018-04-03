	fatal_dump("comm_close: not a SOCKET");
    fde->open = 0;
    RWStateCallbackAndFree(fd, COMM_ERROR);
    fdstat_close(fd);		/* update fdstat */
    commCallCloseHandlers(fd);
    memset(fde, '\0', sizeof(FD_ENTRY));
#if USE_ASYNC_IO
    aioClose(fd);
#else
    fde->lifetime = -1;
    close(fd);
#endif
}
