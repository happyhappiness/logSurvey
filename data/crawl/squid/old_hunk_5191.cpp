    context->writeComplete (fd, bufnotused, size, errflag);
}

void
ClientSocketContext::writeComplete(int fd, char *bufnotused, size_t size, comm_err_t errflag)
{
