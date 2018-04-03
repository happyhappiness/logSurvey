 SQUIDCEXTERN void commSetCloseOnExec(int fd);
 SQUIDCEXTERN void commSetTcpKeepalive(int fd, int idle, int interval, int timeout);
 extern void _comm_close(int fd, char const *file, int line);
-extern void _comm_close(Comm::Connection::Pointer conn, char const *file, int line);
+extern void _comm_close(Comm::ConnectionPointer conn, char const *file, int line);
 #define comm_close(x) (_comm_close((x), __FILE__, __LINE__))
 SQUIDCEXTERN void comm_reset_close(int fd);
 #if LINGERING_CLOSE
