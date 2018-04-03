 extern int printf (const char *format, ...)
        __attribute__ ((__format__ (__printf__, 1, 2)));
 # endif
+#elif @GNULIB_PRINTF@ && @REPLACE_STDIO_WRITE_FUNCS@ && @GNULIB_STDIO_H_SIGPIPE@
+/* Don't break __attribute__((format(printf,M,N))).  */
+# define printf __printf__
+extern int printf (const char *format, ...)
+       __attribute__ ((__format__ (__printf__, 1, 2)));
 #elif defined GNULIB_POSIXCHECK
 # undef printf
 # define printf \
