# define CLOSE_ON_EXEC(_d) (void) fcntl ((_d), F_SETFD, FD_CLOEXEC)
#endif

#ifdef OUTPUT_SYNC
# ifdef WINDOWS32
/* For emulations in w32/compat/posixfcn.c.  */
#  define F_GETFD 1
