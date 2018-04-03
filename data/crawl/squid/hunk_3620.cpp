 
 /************* END CONFIGURATION ***************/
 
-#include <sys/types.h>
-
-
-/* Debugging stuff */
-#ifndef debug /* already provided */
-#ifdef __GNUC__			/* this is really a gcc-ism */
-#ifdef DEBUG
-#include <stdio.h>
-#include <unistd.h>
-static const char *__foo;
-extern int debug_enabled;
-#define debug(X...) if (debug_enabled) { \
-                    fprintf(stderr,"ntlm-auth[%ld](%s:%d): ", (long)getpid(), \
-                    ((__foo=strrchr(__FILE__,'/'))==NULL?__FILE__:__foo+1),\
-                    __LINE__);\
-                    fprintf(stderr,X); }
-#else /* DEBUG */
-#define debug(X...)		/* */
-#endif /* DEBUG */
-#else /* __GNUC__ */
-static void
-debug(char *format,...)
-{
-}
-#endif
-#endif /* debug already defined */
 
 /* A couple of harmless helper macros */
 #define SEND(X) debug("sending '%s' to squid\n",X); printf(X "\n");
