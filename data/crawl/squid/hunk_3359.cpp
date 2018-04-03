 SQUIDCEXTERN void commSetCloseOnExec(int fd);
 SQUIDCEXTERN void commSetTcpKeepalive(int fd, int idle, int interval, int timeout);
 extern void _comm_close(int fd, char const *file, int line);
-#define comm_close(fd) (_comm_close((fd), __FILE__, __LINE__))
+extern void _comm_close(Comm::Connection *conn, char const *file, int line);
+#define comm_close(x) (_comm_close((x), __FILE__, __LINE__))
 SQUIDCEXTERN void comm_reset_close(int fd);
 #if LINGERING_CLOSE
 SQUIDCEXTERN void comm_lingering_close(int fd);
