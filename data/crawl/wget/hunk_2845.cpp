 
 #ifdef ENABLE_DEBUG
 /* The same as logprintf(), but does anything only if opt.debug is
-   non-zero.  */
+   true.  */
 void
 debug_logprintf (const char *fmt, ...)
 {
