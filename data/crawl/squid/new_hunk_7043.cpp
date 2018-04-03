file_read(int fd, char *buf, int req_len, int offset, DRCB * handler, void *client_data)
{
    dread_ctrl *ctrl_dat;
    assert(fd >= 0);
    ctrl_dat = xcalloc(1, sizeof(dread_ctrl));
    ctrl_dat->fd = fd;
    ctrl_dat->offset = offset;
    ctrl_dat->req_len = req_len;
    ctrl_dat->buf = buf;
    ctrl_dat->end_of_file = 0;
    ctrl_dat->handler = handler;
    ctrl_dat->client_data = client_data;
    debug(0,0)("file_read: FD %d queueing read for %d bytes at %d\n", fd, req_len, offset);
#if USE_ASYNC_IO
    diskHandleRead(fd, ctrl_dat);
#else
