file_open_fd(int fd, const char *name, unsigned int type)
{
    FD_ENTRY *fde = &fd_table[fd];
    if (fde->open)
	fatal_dump("file_open_fd: already open");
    memset(fde, '\0', sizeof(FD_ENTRY));
    fdstat_open(fd, type);
    commSetCloseOnExec(fd);
    xstrncpy(fde->disk.filename, name, SQUID_MAXPATHLEN);
}
