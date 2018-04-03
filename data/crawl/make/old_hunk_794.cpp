
/* Fancy processing for variadic functions in both ANSI and pre-ANSI
   compilers.  */
#if defined __STDC__ && __STDC__
extern void message (int prefix, const char *fmt, ...)
                     __attribute__ ((__format__ (__printf__, 2, 3)));
extern void error (const struct floc *flocp, const char *fmt, ...)
