 };
 
 /* Legacy API */
-extern Logfile *logfileOpen(const char *path, size_t bufsz, int);
-extern void logfileClose(Logfile * lf);
-extern void logfileRotate(Logfile * lf);
-extern void logfileWrite(Logfile * lf, char *buf, size_t len);
-extern void logfileFlush(Logfile * lf);
-extern void logfilePrintf(Logfile * lf, const char *fmt,...) PRINTF_FORMAT_ARG2;
-extern void logfileLineStart(Logfile * lf);
-extern void logfileLineEnd(Logfile * lf);
+Logfile *logfileOpen(const char *path, size_t bufsz, int);
+void logfileClose(Logfile * lf);
+void logfileRotate(Logfile * lf);
+void logfileWrite(Logfile * lf, char *buf, size_t len);
+void logfileFlush(Logfile * lf);
+void logfilePrintf(Logfile * lf, const char *fmt,...) PRINTF_FORMAT_ARG2;
+void logfileLineStart(Logfile * lf);
+void logfileLineEnd(Logfile * lf);
 
 #endif /* SQUID_SRC_LOG_FILE_H */
