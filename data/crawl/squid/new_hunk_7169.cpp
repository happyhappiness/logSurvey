{
    FD_ENTRY *fde = NULL;
    debug(5, 5) ("comm_close: FD %d\n", fd);
    assert(fd >= 0);
    assert(fd < Squid_MaxFD);
    fde = &fd_table[fd];
    if (!fde->open)
	return;
    assert(fd_table[fd].type =! FD_FILE);
    fde->open = 0;
    CommWriteStateCallbackAndFree(fd, COMM_ERROR);
    commCallCloseHandlers(fd);
