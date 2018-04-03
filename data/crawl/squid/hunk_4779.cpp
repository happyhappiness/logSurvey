 #ifndef __COMM_H__
 #define __COMM_H__
 
+#include "squid.h"
 #include "StoreIOBuffer.h"
 #include "Array.h"
 
+typedef enum {
+    COMM_OK = 0,
+    COMM_ERROR = -1,
+    COMM_NOMESSAGE = -3,
+    COMM_TIMEOUT = -4,
+    COMM_SHUTDOWN = -5,
+    COMM_IDLE = -6, /* there are no active fds and no pending callbacks. */
+    COMM_INPROGRESS = -7,
+    COMM_ERR_CONNECT = -8,
+    COMM_ERR_DNS = -9,
+    COMM_ERR_CLOSING = -10,
+} comm_err_t;
 typedef void IOFCB(int fd, StoreIOBuffer recievedData, comm_err_t flag, int xerrno, void *data);
 typedef void IOWCB(int fd, char *buffer, size_t len, comm_err_t flag, int xerrno, void *data);
+
+typedef void CWCB(int fd, char *, size_t size, comm_err_t flag, void *data);
+typedef void CNCB(int fd, comm_err_t status, int xerrno, void *data);
+
+typedef void IOCB(int fd, char *, size_t size, comm_err_t flag, int xerrno, void *data);
+
+struct _CommWriteStateData
+{
+    char *buf;
+    size_t size;
+    off_t offset;
+    CWCB *handler;
+    void *handler_data;
+    FREE *free_func;
+};
+
+/* comm.c */
+extern void comm_calliocallback(void);
+extern bool comm_iocallbackpending(void); /* inline candidate */
+
+extern int comm_listen(int fd);
+SQUIDCEXTERN int commSetNonBlocking(int fd);
+SQUIDCEXTERN int commUnsetNonBlocking(int fd);
+SQUIDCEXTERN void commSetCloseOnExec(int fd);
+extern void _comm_close(int fd, char const *file, int line);
+#define comm_close(fd) (_comm_close((fd), __FILE__, __LINE__))
+SQUIDCEXTERN void comm_reset_close(int fd);
+#if LINGERING_CLOSE
+SQUIDCEXTERN void comm_lingering_close(int fd);
+#endif
+SQUIDCEXTERN void commConnectStart(int fd, const char *, u_short, CNCB *, void *);
+
+SQUIDCEXTERN int comm_connect_addr(int sock, const struct sockaddr_in *);
+SQUIDCEXTERN void comm_init(void);
+
+SQUIDCEXTERN int comm_open(int, int, struct IN_ADDR, u_short port, int, const char *note);
+
+SQUIDCEXTERN int comm_openex(int, int, struct IN_ADDR, u_short, int, unsigned char TOS, const char *);
+SQUIDCEXTERN u_short comm_local_port(int fd);
+
+SQUIDCEXTERN void commSetSelect(int, unsigned int, PF *, void *, time_t);
+
+SQUIDCEXTERN int comm_udp_sendto(int, const struct sockaddr_in *, int, const void *, int);
+SQUIDCEXTERN void comm_old_write(int fd,
+                                 const char *buf,
+                                 int size,
+                                 CWCB * handler,
+                                 void *handler_data,
+                                 FREE *);
+SQUIDCEXTERN void comm_old_write_mbuf(int fd, MemBuf *mb, CWCB * handler, void *handler_data);
+SQUIDCEXTERN void commCallCloseHandlers(int fd);
+SQUIDCEXTERN int commSetTimeout(int fd, int, PF *, void *);
+SQUIDCEXTERN int ignoreErrno(int);
+SQUIDCEXTERN void commCloseAllSockets(void);
+SQUIDCEXTERN void checkTimeouts(void);
+
+
+/*
+ * comm_select.c
+ */
+SQUIDCEXTERN void comm_select_init(void);
+SQUIDCEXTERN comm_err_t comm_select(int);
+SQUIDCEXTERN void comm_quick_poll_required(void);
+
 /* fill sb with up to length data from fd */
 extern void comm_fill_immediate(int fd, StoreIOBuffer sb, IOFCB *callback, void *data);
 
