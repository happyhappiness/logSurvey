#ifndef errno
extern int errno;
#endif

/* We expect no message passed to logprintf() to be bigger than this.
   Before a message is printed, we make sure that at least this much
   room is left for printing it.  */
#define SAVED_LOG_MAXMSG 32768

/* Maximum allowed growing size.  */
#define SAVED_LOG_MAXSIZE (10 * 1L << 20)

static char *saved_log;
/* Size of the current log.  */
static long saved_log_size;
/* Offset into the log where we are about to print (size of the
   used-up part of SAVED_LOG).  */
static long saved_log_offset;
/* Whether logging is saved at all.  */
int save_log_p;

static FILE *logfp;

/* Check X against opt.verbose and opt.quiet.  The semantics is as
   follows:

