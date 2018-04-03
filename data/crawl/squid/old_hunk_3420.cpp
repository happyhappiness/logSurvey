#include <unistd.h>
static char *__foo;
extern char debug_enabled;
#define debug(X...) if (debug_enabled) { \
                    fprintf(stderr,"%s[%d](%s:%d): ", myname, mypid, \
                    ((__foo=strrchr(__FILE__,'/'))==NULL?__FILE__:__foo+1),\
                    __LINE__);\
                    fprintf(stderr,X); }
#else /* DEBUG */
#define debug(X...)		/* */
#endif /* DEBUG */
#else /* __GNUC__ */
extern char debug_enabled;
static void
debug(char *format,...)
{
#ifdef DEBUG
#ifdef _SQUID_MSWIN_
    if (debug_enabled) {
        va_list args;

        va_start(args, format);
        fprintf(stderr, "%s[%d]: ", myname, mypid);
        vfprintf(stderr, format, args);
        fprintf(stderr, "\n");
        va_end(args);
    }
#endif /* _SQUID_MSWIN_ */
#endif /* DEBUG */
