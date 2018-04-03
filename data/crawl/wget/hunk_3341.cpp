 #ifdef DEBUG
 /* The same as logprintf(), but does anything only if opt.debug is
    non-zero.  */
-#ifdef WGET_USE_STDARG
 void
 debug_logprintf (const char *fmt, ...)
-#else  /* not WGET_USE_STDARG */
-void
-debug_logprintf (va_alist)
-     va_dcl
-#endif /* not WGET_USE_STDARG */
 {
   if (opt.debug)
     {
       va_list args;
-#ifndef WGET_USE_STDARG
-      const char *fmt;
-#endif
       struct logvprintf_state lpstate;
       int done;
 
