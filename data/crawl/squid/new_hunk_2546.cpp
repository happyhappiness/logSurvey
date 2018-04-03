SQUIDCEXTERN void commSetCloseOnExec(int fd);
SQUIDCEXTERN void commSetTcpKeepalive(int fd, int idle, int interval, int timeout);
extern void _comm_close(int fd, char const *file, int line);
#define comm_close(x) (_comm_close((x), __FILE__, __LINE__))
SQUIDCEXTERN void old_comm_reset_close(int fd);
SQUIDCEXTERN void comm_reset_close(Comm::ConnectionPointer &conn);
#if LINGERING_CLOSE
SQUIDCEXTERN void comm_lingering_close(int fd);
#endif

SQUIDCEXTERN int comm_connect_addr(int sock, const Ip::Address &addr);
SQUIDCEXTERN void comm_init(void);
