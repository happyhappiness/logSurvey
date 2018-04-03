
static int Verbose, Quiet;

static void imap_info(const char *, ...);
static void imap_warn(const char *, ...);

static char *next_arg(char **);

static void free_generic_messages(struct message *);

static int nfsnprintf(char *buf, int blen, const char *fmt, ...);

static int nfvasprintf(char **strp, const char *fmt, va_list ap)
