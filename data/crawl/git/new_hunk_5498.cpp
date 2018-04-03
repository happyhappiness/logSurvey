
static int Verbose, Quiet;

__attribute__((format (printf, 1, 2)))
static void imap_info(const char *, ...);
__attribute__((format (printf, 1, 2)))
static void imap_warn(const char *, ...);

static char *next_arg(char **);

static void free_generic_messages(struct message *);

__attribute__((format (printf, 3, 4)))
static int nfsnprintf(char *buf, int blen, const char *fmt, ...);

static int nfvasprintf(char **strp, const char *fmt, va_list ap)
