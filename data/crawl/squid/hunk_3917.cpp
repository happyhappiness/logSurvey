 SQUIDCEXTERN void logfileRotate(Logfile * lf);
 SQUIDCEXTERN void logfileWrite(Logfile * lf, void *buf, size_t len);
 SQUIDCEXTERN void logfileFlush(Logfile * lf);
-#if STDC_HEADERS
-SQUIDCEXTERN void
-logfilePrintf(Logfile * lf, const char *fmt,...) PRINTF_FORMAT_ARG2;
-#else
-SQUIDCEXTERN void logfilePrintf(va_alist);
-#endif
+SQUIDCEXTERN void logfilePrintf(Logfile * lf, const char *fmt,...) PRINTF_FORMAT_ARG2;
 
 /*
  * prototypes for system functions missing from system includes
