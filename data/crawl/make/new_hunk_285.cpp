# define CLOSE_ON_EXEC(_d) (void) fcntl ((_d), F_SETFD, FD_CLOEXEC)
#endif

#ifdef NO_OUTPUT_SYNC
# define RECORD_SYNC_MUTEX(m) \
    error (NILF, \
           _("-O[TYPE] (--output-sync[=TYPE]) is not configured for this build."));
#else
# ifdef WINDOWS32
/* For emulations in w32/compat/posixfcn.c.  */
#  define F_GETFD 1
