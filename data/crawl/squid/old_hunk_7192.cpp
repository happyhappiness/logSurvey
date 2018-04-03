commSetTimeout(int fd, int timeout, PF * handler, void *data)
{
    FD_ENTRY *fde;
    debug(5, 3, "commSetTimeout: FD %d timeout %d\n", fd, timeout);
    if (fd < 0 || fd > Squid_MaxFD)
	fatal_dump("commSetTimeout: bad FD");
    fde = &fd_table[fd];
