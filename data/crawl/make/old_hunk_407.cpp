#define STRING_SIZE_TUPLE(_s) (_s), CSTRLEN(_s)


/* We have to have stdarg.h or varargs.h AND v*printf or doprnt to use
   variadic versions of these functions.  */

#if HAVE_STDARG_H || HAVE_VARARGS_H
# if HAVE_VPRINTF || HAVE_DOPRNT
#  define USE_VARIADIC 1
# endif
#endif

#if HAVE_ANSI_COMPILER && USE_VARIADIC && HAVE_STDARG_H
const char *concat (unsigned int, ...);
void message (int prefix, const char *fmt, ...)
              __attribute__ ((__format__ (__printf__, 2, 3)));
