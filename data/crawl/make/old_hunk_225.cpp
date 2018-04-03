
#define NILF ((gmk_floc *)0)

#define CSTRLEN(_s) (sizeof (_s)-1)
#define STRING_SIZE_TUPLE(_s) (_s), CSTRLEN(_s)


const char *concat (unsigned int, ...);
void message (int prefix, const char *fmt, ...)
              __attribute__ ((__format__ (__printf__, 2, 3)));
void error (const gmk_floc *flocp, const char *fmt, ...)
            __attribute__ ((__format__ (__printf__, 2, 3)));
void fatal (const gmk_floc *flocp, const char *fmt, ...)
                   __attribute__ ((noreturn, __format__ (__printf__, 2, 3)));

void die (int) __attribute__ ((noreturn));
void pfatal_with_name (const char *) __attribute__ ((noreturn));
