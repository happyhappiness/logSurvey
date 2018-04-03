# define DEBUGP(x) DO_NOTHING
#endif /* not ENABLE_DEBUG */

/* Make gcc check for the format of logmsg() and debug_logmsg().  */
#ifdef __GNUC__
# define GCC_FORMAT_ATTR(a, b) __attribute__ ((format (printf, a, b)))
#else  /* not __GNUC__ */
# define GCC_FORMAT_ATTR(a, b)
#endif /* not __GNUC__ */

/* These are from log.c, but they are used everywhere, so we declare
   them here.  */
enum log_options { LOG_VERBOSE, LOG_NOTQUIET, LOG_NONVERBOSE, LOG_ALWAYS };

#ifdef HAVE_STDARG_H
void logprintf PARAMS ((enum log_options, const char *, ...))
     GCC_FORMAT_ATTR (2, 3);
void debug_logprintf PARAMS ((const char *, ...)) GCC_FORMAT_ATTR (1, 2);
#else  /* not HAVE_STDARG_H */
void logprintf ();
void debug_logprintf ();
#endif /* not HAVE_STDARG_H */
void logputs PARAMS ((enum log_options, const char *));
void logflush PARAMS ((void));
void log_set_flush PARAMS ((int));
int log_set_save_context PARAMS ((int));

/* Defined in `utils.c', but used literally everywhere.  */
#ifndef DEBUG_MALLOC

#define xmalloc  xmalloc_real
#define xrealloc xrealloc_real
#define xstrdup  xstrdup_real
#define xfree    free

void *xmalloc_real PARAMS ((size_t));
void *xrealloc_real PARAMS ((void *, size_t));
char *xstrdup_real PARAMS ((const char *));

#else  /* DEBUG_MALLOC */

#define xmalloc(s)     xmalloc_debug (s, __FILE__, __LINE__)
#define xfree(p)       xfree_debug (p, __FILE__, __LINE__)
#define xrealloc(p, s) xrealloc_debug (p, s, __FILE__, __LINE__)
#define xstrdup(p)     xstrdup_debug (p, __FILE__, __LINE__)

void *xmalloc_debug PARAMS ((size_t, const char *, int));
void xfree_debug PARAMS ((void *, const char *, int));
void *xrealloc_debug PARAMS ((void *, size_t, const char *, int));
char *xstrdup_debug PARAMS ((const char *, const char *, int));

#endif /* DEBUG_MALLOC */

/* #### Find a better place for this.  */
/* The log file to which Wget writes to after HUP.  */
#define DEFAULT_LOGFILE "wget-log"

#define MD5_HASHLEN 16

/* Useful macros used across the code: */

/* Is the string a hpyhen-only?  */
#define HYPHENP(x) (*(x) == '-' && !*((x) + 1))

/* The smaller value of the two.  */
#define MINVAL(x, y) ((x) < (y) ? (x) : (y))

/* Convert an ASCII hex digit to the corresponding number between 0
   and 15.  X should be a hexadecimal digit that satisfies isxdigit;
   otherwise, the result is undefined.  */
#define XDIGIT_TO_NUM(x) ((x) < 'A' ? (x) - '0' : TOUPPER (x) - 'A' + 10)

/* Convert a sequence of ASCII hex digits X and Y to a number betewen
   0 and 255.  Uses XDIGIT_TO_NUM for conversion of individual
   digits.  */
#define X2DIGITS_TO_NUM(h1, h2) ((XDIGIT_TO_NUM (h1) << 4) + XDIGIT_TO_NUM (h2))

/* The reverse of the above: convert a number in the [0, 16) range to
   its ASCII representation in hex.  The A-F characters are in upper
   case.  */
#define XNUM_TO_DIGIT(x) ("0123456789ABCDEF"[x])

/* Like XNUM_TO_DIGIT, but generates lower-case characters. */
#define XNUM_TO_digit(x) ("0123456789abcdef"[x])

/* Returns the number of elements in an array with fixed
   initialization.  For example:

   static char a[] = "foo";     -- countof(a) == 4 (for terminating \0)

   int a[5] = {1, 2};           -- countof(a) == 5

   char *a[] = {                -- countof(a) == 3
     "foo", "bar", "baz"
   }; */
#define countof(array) (sizeof (array) / sizeof (*(array)))

#define alloca_array(type, size) ((type *) alloca ((size) * sizeof (type)))

/* Copy the data delimited with BEG and END to alloca-allocated
   storage, and zero-terminate it.  Arguments are evaluated only once,
