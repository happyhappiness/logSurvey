file_read(int fd, char *buf, int req_len, int offset, DRCB * handler, void *client_data)
{
    dread_ctrl *ctrl_dat;
    if (fd < 0)
	fatal_dump("file_read: bad FD");
    ctrl_dat = xcalloc(1, sizeof(dread_ctrl));
    ctrl_dat->fd = fd;
    ctrl_dat->offset = offset;
    ctrl_dat->req_len = req_len;
    ctrl_dat->buf = buf;
    ctrl_dat->offset = 0;
    ctrl_dat->end_of_file = 0;
    ctrl_dat->handler = handler;
    ctrl_dat->client_data = client_data;
#if USE_ASYNC_IO
    diskHandleRead(fd, ctrl_dat);
#else
