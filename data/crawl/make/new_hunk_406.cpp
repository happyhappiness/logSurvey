

const char *concat (unsigned int, ...);
const char *message_s (unsigned int length, int prefix, const char *fmt, ...)
              __attribute__ ((__format__ (__printf__, 3, 4)));
const char *error_s (unsigned int length, const gmk_floc *flocp, const char *fmt, ...)
              __attribute__ ((__format__ (__printf__, 3, 4)));
void message (int prefix, const char *fmt, ...)
              __attribute__ ((__format__ (__printf__, 2, 3)));
void error (const gmk_floc *flocp, const char *fmt, ...)
