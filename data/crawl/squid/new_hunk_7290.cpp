void
comm_close(int fd)
{
    FD_ENTRY *fde = NULL;
    debug(5, 5, "comm_close: FD %d\n", fd);
    if (fd < 0)
    	fatal_dump("comm_close: bad FD");
    if (fd >= Squid_MaxFD)
    	fatal_dump("comm_close: bad FD");
    fde = &fd_table[fd];
    if (!fde->open)
	return;
    if (fd_table[fd].type == FD_FILE)
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
