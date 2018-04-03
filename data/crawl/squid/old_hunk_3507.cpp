/* for shutting_down flag in xassert() */
#include "globals.h"

/* cope with no squid.h */
#ifndef MAXPATHLEN
#define MAXPATHLEN 256
#endif

char *Debug::debugOptions = NULL;
int Debug::override_X = 0;
int Debug::log_stderr = -1;
