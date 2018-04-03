 #ifdef DEBUG
 #include <stdio.h>
 #include <unistd.h>
-static char *__foo;
+static const char *__foo;
 #define debug(X...) if (debug_enabled) { \
-                    fprintf(stderr,"ntlm-auth[%d](%s:%d): ", (int)getpid(), \
+                    fprintf(stderr,"ntlm-auth[%ld](%s:%d): ", (long)getpid(), \
                     ((__foo=strrchr(__FILE__,'/'))==NULL?__FILE__:__foo+1),\
                     __LINE__);\
                     fprintf(stderr,X); }
