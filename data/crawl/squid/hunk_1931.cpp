                     ((__foo=strrchr(__FILE__,'/'))==NULL?__FILE__:__foo+1),\
                     __LINE__);\
                     fprintf(stderr,X); }
-#else /* DEBUG */
-#define debug(X...)		/* */
-#endif /* DEBUG */
 #else /* __GNUC__ */
 static void
 debug(char *format,...)
 {
-#ifdef DEBUG
-#if _SQUID_MSWIN_
     if (debug_enabled) {
         va_list args;
 
