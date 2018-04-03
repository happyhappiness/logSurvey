
extern void clientAccessCheck(void *);

/* comm.c */
extern void comm_calliocallback(void);
extern bool comm_iocallbackpending(void); /* inline candidate */

extern int comm_listen(int fd);
SQUIDCEXTERN int commSetNonBlocking(int fd);
SQUIDCEXTERN int commUnsetNonBlocking(int fd);
SQUIDCEXTERN void commSetCloseOnExec(int fd);
extern void _comm_close(int fd, char const *file, int line);
#define comm_close(fd) (_comm_close((fd), __FILE__, __LINE__))
SQUIDCEXTERN void comm_reset_close(int fd);
#if LINGERING_CLOSE
SQUIDCEXTERN void comm_lingering_close(int fd);
#endif
SQUIDCEXTERN void commConnectStart(int fd, const char *, u_short, CNCB *, void *);

SQUIDCEXTERN int comm_connect_addr(int sock, const struct sockaddr_in *);
SQUIDCEXTERN void comm_init(void);

SQUIDCEXTERN int comm_open(int, int, struct IN_ADDR, u_short port, int, const char *note);

SQUIDCEXTERN int comm_openex(int, int, struct IN_ADDR, u_short, int, unsigned char TOS, const char *);
SQUIDCEXTERN u_short comm_local_port(int fd);

SQUIDCEXTERN void commSetSelect(int, unsigned int, PF *, void *, time_t);

SQUIDCEXTERN int comm_udp_sendto(int, const struct sockaddr_in *, int, const void *, int);
SQUIDCEXTERN void comm_old_write(int fd,
                                 const char *buf,
                                 int size,
                                 CWCB * handler,
                                 void *handler_data,
                                 FREE *);
SQUIDCEXTERN void comm_old_write_mbuf(int fd, MemBuf *mb, CWCB * handler, void *handler_data);
SQUIDCEXTERN void commCallCloseHandlers(int fd);
SQUIDCEXTERN int commSetTimeout(int fd, int, PF *, void *);
SQUIDCEXTERN int ignoreErrno(int);
SQUIDCEXTERN void commCloseAllSockets(void);
SQUIDCEXTERN void checkTimeouts(void);


/*
 * comm_select.c
 */
SQUIDCEXTERN void comm_select_init(void);
SQUIDCEXTERN comm_err_t comm_select(int);
SQUIDCEXTERN void comm_quick_poll_required(void);


/* see debug.c for info on context-based debugging */
SQUIDCEXTERN Ctx ctx_enter(const char *descr);
SQUIDCEXTERN void ctx_exit(Ctx ctx);
