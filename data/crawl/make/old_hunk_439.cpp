const char *concat (unsigned int, ...);
void message (int prefix, const char *fmt, ...)
              __attribute__ ((__format__ (__printf__, 2, 3)));
void error (const struct floc *flocp, const char *fmt, ...)
            __attribute__ ((__format__ (__printf__, 2, 3)));
void fatal (const struct floc *flocp, const char *fmt, ...)
                   __attribute__ ((noreturn, __format__ (__printf__, 2, 3)));
#else
const char *concat ();
