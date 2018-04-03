void DeferredReadManager::delayRead(DeferredRead const &aRead) STUB
void DeferredReadManager::kickReads(int const count) STUB

void commSetCloseOnExec(int fd) STUB_NOP
int ignoreErrno(int ierrno) STUB_RETVAL(-1)

void commUnsetFdTimeout(int fd) STUB
int commSetNonBlocking(int fd) STUB_RETVAL(COMM_ERROR)
int commUnsetNonBlocking(int fd) STUB_RETVAL(-1)

// MinGW needs also a stub of _comm_close()
void _comm_close(int fd, char const *file, int line) STUB
int commSetTimeout(int fd, int timeout, AsyncCall::Pointer& callback) STUB_RETVAL(-1)
int comm_open_uds(int sock_type, int proto, struct sockaddr_un* addr, int flags) STUB_RETVAL(-1)
void comm_write(int fd, const char *buf, int size, AsyncCall::Pointer &callback, FREE * free_func) STUB
