

/* Debugging stuff */

#ifdef __GNUC__			/* this is really a gcc-ism */
#ifdef DEBUG
#include <stdio.h>
#include <unistd.h>
static const char *__foo;
extern char debug_enabled;
#define debug(X...) if (debug_enabled) { \
                    fprintf(stderr,"ntlm-auth[%ld](%s:%d): ", (long)getpid(), \
                    ((__foo=strrchr(__FILE__,'/'))==NULL?__FILE__:__foo+1),\
