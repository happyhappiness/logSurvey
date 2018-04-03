fd_close(int fd)
{
    FD_ENTRY *fde = &fd_table[fd];
    fdUpdateBiggest(fd, fde->open = FD_CLOSE);
    memset(fde, '\0', sizeof(FD_ENTRY));
    fde->timeout = 0;
