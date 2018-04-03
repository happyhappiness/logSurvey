#define STRING_SIZE_TUPLE(_s) (_s), CSTRLEN(_s)


const char *concat (unsigned int, ...);
void message (int prefix, const char *fmt, ...)
              __attribute__ ((__format__ (__printf__, 2, 3)));
