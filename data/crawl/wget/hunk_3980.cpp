 #ifdef DEBUG
 /* The same as logprintf(), but does anything only if opt.debug is
    non-zero.  */
-#ifdef USE_STDARG
+#ifdef WGET_USE_STDARG
 void
 debug_logprintf (const char *fmt, ...)
-#else  /* not USE_STDARG */
+#else  /* not WGET_USE_STDARG */
 void
 debug_logprintf (va_alist)
      va_dcl
-#endif /* not USE_STDARG */
+#endif /* not WGET_USE_STDARG */
 {
   if (opt.debug)
     {
       va_list args;
-#ifndef USE_STDARG
+#ifndef WGET_USE_STDARG
       const char *fmt;
 #endif
 
-#ifdef USE_STDARG
+#ifdef WGET_USE_STDARG
       va_start (args, fmt);
 #else
       va_start (args);
