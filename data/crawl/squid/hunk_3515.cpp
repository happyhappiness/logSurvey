 SQUIDCEXTERN void *leakFreeFL(void *, const char *, int);
 #endif
 
-/* logfile.c */
-SQUIDCEXTERN Logfile *logfileOpen(const char *path, size_t bufsz, int);
-SQUIDCEXTERN void logfileClose(Logfile * lf);
-SQUIDCEXTERN void logfileRotate(Logfile * lf);
-SQUIDCEXTERN void logfileWrite(Logfile * lf, void *buf, size_t len);
-SQUIDCEXTERN void logfileFlush(Logfile * lf);
-SQUIDCEXTERN void logfilePrintf(Logfile * lf, const char *fmt,...) PRINTF_FORMAT_ARG2;
-
 /*
  * prototypes for system functions missing from system includes
  */
