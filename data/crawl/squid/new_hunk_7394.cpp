file_read(int fd, char *buf, int req_len, int offset, FILE_READ_HD handler, void *client_data)
{
    dread_ctrl *ctrl_dat;
    if (fd < 0)
       fatal_dump("file_read: bad FD");
    ctrl_dat = xcalloc(1, sizeof(dread_ctrl));
    ctrl_dat->fd = fd;
    ctrl_dat->offset = offset;
