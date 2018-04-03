file_open_fd(int fd, const char *name, unsigned int type)
{
    FD_ENTRY *fde = &fd_table[fd];
    fd_open(fd, type, name);
    commSetCloseOnExec(fd);
    xstrncpy(fde->disk.filename, name, SQUID_MAXPATHLEN);
}
