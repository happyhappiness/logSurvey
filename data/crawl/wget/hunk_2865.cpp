   return old;
 }
 
-/* Handle difference in va_start between pre-ANSI and ANSI C.  Note
-   that we always use `...' in function definitions and let ansi2knr
-   convert it for us.  */
-
-#ifdef WGET_USE_STDARG
-# define VA_START(args, arg1) va_start (args, arg1)
-#else
-# define VA_START(args, ignored) va_start (args)
-#endif
-
 /* Print a message to the screen or to the log.  The first argument
    defines the verbosity of the message, and the rest are as in
    printf(3).  */
