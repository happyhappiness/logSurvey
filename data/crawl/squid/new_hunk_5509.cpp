SQUIDCEXTERN int clientHttpRequestStatus(int fd, clientHttpRequest const *http);
SQUIDCEXTERN void clientSetReplyToError(void *, err_type, http_status, method_t, char const *, struct in_addr *, request_t *, char *, auth_user_request_t * auth_user_request);

/* comm.c */
extern int comm_existsiocallback(void);
extern void comm_calliocallback(void);
extern void comm_read(int fd, char *buf, int len, IOCB *handler, void *data);

extern void comm_accept(int fd, IOACB *handler, void *handler_data);
extern int comm_listen(int fd);
SQUIDCEXTERN int commSetNonBlocking(int fd);
SQUIDCEXTERN int commUnsetNonBlocking(int fd);
SQUIDCEXTERN void commSetCloseOnExec(int fd);
extern int comm_old_accept(int fd, struct sockaddr_in *, struct sockaddr_in *);
extern void _comm_close(int fd, char *file, int line);
#define comm_close(fd) (_comm_close((fd), __FILE__, __LINE__))
SQUIDCEXTERN void comm_reset_close(int fd);
#if LINGERING_CLOSE
SQUIDCEXTERN void comm_lingering_close(int fd);
#endif
SQUIDCEXTERN void commConnectStart(int fd, const char *, u_short, CNCB *, void *);
SQUIDCEXTERN int comm_connect_addr(int sock, const struct sockaddr_in *);
SQUIDCEXTERN void comm_init(void);
SQUIDCEXTERN int comm_open(int, int, struct in_addr, u_short port, int, const char *note);
SQUIDCEXTERN int comm_openex(int, int, struct in_addr, u_short, int, unsigned char TOS, const char *);
SQUIDCEXTERN u_short comm_local_port(int fd);
