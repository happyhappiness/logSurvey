     /** unfirtunate hack to test if the buffer has been Init()ialized */
     int isNull();
 
-#if STDC_HEADERS
-
     /**
      * calls snprintf, extends buffer if needed
      \note  we use Printf instead of printf so the compiler won't
      *      think we're calling the libc printf()
      */
     void Printf(const char *fmt,...) PRINTF_FORMAT_ARG2;
-#else
-
-    /**
-     * calls snprintf, extends buffer if needed
-     \note  we use Printf instead of printf so the compiler won't
-     *      think we're calling the libc printf()
-     */
-    void Printf();
-#endif
 
     /** vPrintf for other printf()'s to use */
     void vPrintf(const char *fmt, va_list ap);
