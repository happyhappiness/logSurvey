#include <unistd.h>
static char *__foo;
extern char debug_enabled;
extern char *WIN32_ErrorMessage;
#define debug(X...) if (debug_enabled) { \
                    fprintf(stderr,"%s[%d](%s:%d): ", myname, mypid, \
                    ((__foo=strrchr(__FILE__,'/'))==NULL?__FILE__:__foo+1),\
                    __LINE__);\
                    fprintf(stderr,X); \
                    if (WIN32_ErrorMessage != NULL){ \
                    LocalFree(WIN32_ErrorMessage); \
                    WIN32_ErrorMessage = NULL; \
                    } }
#else /* DEBUG */
#define debug(X...)		/* */
#endif /* DEBUG */
#else /* __GNUC__ */
extern char debug_enabled;
extern char *WIN32_ErrorMessage;
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
	if (WIN32_ErrorMessage != NULL) {
	    LocalFree(WIN32_ErrorMessage);
	    WIN32_ErrorMessage = NULL;
	}
    }
#endif /* _SQUID_MSWIN_ */
#endif /* DEBUG */
