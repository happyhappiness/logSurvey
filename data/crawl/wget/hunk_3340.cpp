   return old;
 }
 
+/* Handle difference in va_start between pre-ANSI and ANSI C.  Note
+   that we always use `...' in function definitions and let ansi2knr
+   convert it for us.  */
+
 #ifdef WGET_USE_STDARG
-# define VA_START_1(arg1_type, arg1, args) va_start(args, arg1)
-# define VA_START_2(arg1_type, arg1, arg2_type, arg2, args) va_start(args, arg2)
-#else  /* not WGET_USE_STDARG */
-# define VA_START_1(arg1_type, arg1, args) do {	\
-  va_start (args);							\
-  arg1 = va_arg (args, arg1_type);					\
-} while (0)
-# define VA_START_2(arg1_type, arg1, arg2_type, arg2, args) do {	\
-  va_start (args);							\
-  arg1 = va_arg (args, arg1_type);					\
-  arg2 = va_arg (args, arg2_type);					\
-} while (0)
-#endif /* not WGET_USE_STDARG */
+# define VA_START(args, arg1) va_start (args, arg1)
+#else
+# define VA_START(args, ignored) va_start (args)
+#endif
 
-/* Portability with pre-ANSI compilers makes these two functions look
-   like @#%#@$@#$.  */
+/* Print a message to the screen or to the log.  The first argument
+   defines the verbosity of the message, and the rest are as in
+   printf(3).  */
 
-#ifdef WGET_USE_STDARG
 void
 logprintf (enum log_options o, const char *fmt, ...)
-#else  /* not WGET_USE_STDARG */
-void
-logprintf (va_alist)
-     va_dcl
-#endif /* not WGET_USE_STDARG */
 {
   va_list args;
   struct logvprintf_state lpstate;
   int done;
 
-#ifndef WGET_USE_STDARG
-  enum log_options o;
-  const char *fmt;
-
-  /* Perform a "dry run" of VA_START_2 to get the value of O. */
-  VA_START_2 (enum log_options, o, char *, fmt, args);
-  va_end (args);
-#endif
-
   check_redirect_output ();
   if (inhibit_logging)
     return;
