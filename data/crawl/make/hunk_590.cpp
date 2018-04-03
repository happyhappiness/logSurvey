 #endif
 
 #if HAVE_ANSI_COMPILER && USE_VARIADIC && HAVE_STDARG_H
+const char *concat (unsigned int, ...);
 void message (int prefix, const char *fmt, ...)
               __attribute__ ((__format__ (__printf__, 2, 3)));
 void error (const struct floc *flocp, const char *fmt, ...)
