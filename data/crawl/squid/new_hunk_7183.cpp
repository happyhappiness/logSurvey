commSetSelect(int fd, unsigned int type, PF * handler, void *client_data, time_t timeout)
{
    FD_ENTRY *fde;
    assert(fd >= 0);
    fde = &fd_table[fd];
    debug(5,5)("commSetSelect: FD %d, handler=%p, data=%p\n", fd, handler, client_data);
    if (type & COMM_SELECT_READ) {
	fde->read_handler = handler;
	fde->read_data = client_data;
