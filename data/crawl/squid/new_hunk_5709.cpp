#include <stdio.h>
#include <unistd.h>
static char *__foo;
extern char debug_enabled;
#define debug(X...) if (debug_enabled) { \
                    fprintf(stderr,"ntlm-auth[%d](%s:%d): ", getpid(), \
                    ((__foo=strrchr(__FILE__,'/'))==NULL?__FILE__:__foo+1),\
                    __LINE__);\
                    fprintf(stderr,X); }
#else /* DEBUG */
#define debug(X...)		/* */
#endif /* DEBUG */
