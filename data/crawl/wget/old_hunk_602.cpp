extern int printf (const char *format, ...)
       __attribute__ ((__format__ (__printf__, 1, 2)));
# endif
#elif defined GNULIB_POSIXCHECK
# undef printf
# define printf \
