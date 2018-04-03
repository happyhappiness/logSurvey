{
    fatal ("Not implemented");
}

int
commSetTimeout(int fd, int timeout, AsyncCall::Pointer& callback)
{
    fatal ("Not implemented");
    return -1;
}

int
comm_open_uds(int sock_type, int proto, struct sockaddr_un* addr, int flags)
{
    fatal ("Not implemented");
    return -1;
}

void
comm_write(int fd, const char *buf, int size, AsyncCall::Pointer &callback, FREE * free_func)
{
    fatal ("Not implemented");
}

ConnectionDetail::ConnectionDetail() : me(), peer()
{
    fatal ("Not implemented");
}
