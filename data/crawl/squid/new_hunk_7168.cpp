{
    FD_ENTRY *fde;
    debug(5, 3) ("commSetTimeout: FD %d timeout %d\n", fd, timeout);
    assert(fd >= 0);
    assert(fd < Squid_MaxFD);
    fde = &fd_table[fd];
    if (timeout < 0) {
	fde->timeout_handler = NULL;
