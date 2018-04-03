 SQUIDCEXTERN void safeunlink(const char *path, int quiet);
 SQUIDCEXTERN void death(int sig);
 SQUIDCEXTERN void fatal(const char *message);
-#if STDC_HEADERS
-SQUIDCEXTERN void
-fatalf(const char *fmt,...) PRINTF_FORMAT_ARG1;
-#else
-SQUIDCEXTERN void fatalf();
-#endif
+SQUIDCEXTERN void fatalf(const char *fmt,...) PRINTF_FORMAT_ARG1;
 SQUIDCEXTERN void fatal_dump(const char *message);
 SQUIDCEXTERN void sigusr2_handle(int sig);
 SQUIDCEXTERN void sig_child(int sig);
