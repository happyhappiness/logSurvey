 void DeferredReadManager::delayRead(DeferredRead const &aRead) STUB
 void DeferredReadManager::kickReads(int const count) STUB
 
-void commSetCloseOnExec(int fd) STUB_NOP
-int ignoreErrno(int ierrno) STUB_RETVAL(-1)
-
-void commUnsetFdTimeout(int fd) STUB
-int commSetNonBlocking(int fd) STUB_RETVAL(COMM_ERROR)
+#include "comm.h"
+bool comm_iocallbackpending(void) STUB_RETVAL(false)
+int commSetNonBlocking(int fd) STUB_RETVAL(Comm::COMM_ERROR)
 int commUnsetNonBlocking(int fd) STUB_RETVAL(-1)
-
-// MinGW needs also a stub of _comm_close()
+void commSetCloseOnExec(int fd) STUB_NOP
+void commSetTcpKeepalive(int fd, int idle, int interval, int timeout) STUB
 void _comm_close(int fd, char const *file, int line) STUB
-int commSetTimeout(int fd, int timeout, AsyncCall::Pointer& callback) STUB_RETVAL(-1)
+void old_comm_reset_close(int fd) STUB
+void comm_reset_close(const Comm::ConnectionPointer &conn) STUB
+#if LINGERING_CLOSE
+void comm_lingering_close(int fd) STUB
+#endif
+int comm_connect_addr(int sock, const Ip::Address &addr) STUB_RETVAL(-1)
+void comm_init(void) STUB
+void comm_exit(void) STUB
+int comm_open(int, int, Ip::Address &, int, const char *note) STUB_RETVAL(-1)
 int comm_open_uds(int sock_type, int proto, struct sockaddr_un* addr, int flags) STUB_RETVAL(-1)
-void comm_write(int fd, const char *buf, int size, AsyncCall::Pointer &callback, FREE * free_func) STUB
+void comm_import_opened(const Comm::ConnectionPointer &, const char *note, struct addrinfo *AI) STUB
+int comm_open_listener(int sock_type, int proto, Ip::Address &addr, int flags, const char *note) STUB_RETVAL(-1)
+void comm_open_listener(int sock_type, int proto, Comm::ConnectionPointer &conn, const char *note) STUB
+int comm_openex(int, int, Ip::Address &, int, tos_t tos, nfmark_t nfmark, const char *) STUB_RETVAL(-1)
+unsigned short comm_local_port(int fd) STUB_RETVAL(0)
+int comm_udp_sendto(int sock, const Ip::Address &to, const void *buf, int buflen) STUB_RETVAL(-1)
+void commCallCloseHandlers(int fd) STUB
+void commUnsetFdTimeout(int fd) STUB
+int commSetTimeout(const Comm::ConnectionPointer &, int, AsyncCall::Pointer&) STUB_RETVAL(-1)
+int commSetConnTimeout(const Comm::ConnectionPointer &conn, int seconds, AsyncCall::Pointer &callback) STUB_RETVAL(-1)
+int commUnsetConnTimeout(const Comm::ConnectionPointer &conn) STUB_RETVAL(-1)
+int ignoreErrno(int ierrno) STUB_RETVAL(-1)
+void commCloseAllSockets(void) STUB
+void checkTimeouts(void) STUB
+void comm_add_close_handler(int fd, CLCB *, void *) STUB
+void comm_add_close_handler(int fd, AsyncCall::Pointer &) STUB
+void comm_remove_close_handler(int fd, CLCB *, void *) STUB
+void comm_remove_close_handler(int fd, AsyncCall::Pointer &)STUB
+int comm_udp_recvfrom(int fd, void *buf, size_t len, int flags, Ip::Address &from) STUB_RETVAL(-1)
+int comm_udp_recv(int fd, void *buf, size_t len, int flags) STUB_RETVAL(-1)
+ssize_t comm_udp_send(int s, const void *buf, size_t len, int flags) STUB_RETVAL(-1)
+bool comm_has_incomplete_write(int) STUB_RETVAL(false)
+void commStartHalfClosedMonitor(int fd) STUB
+bool commHasHalfClosedMonitor(int fd) STUB_RETVAL(false)
+int CommSelectEngine::checkEvents(int timeout) STUB_RETVAL(0)