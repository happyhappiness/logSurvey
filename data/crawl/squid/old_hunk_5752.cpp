extern void logfileWrite(Logfile * lf, void *buf, size_t len);
extern void logfileFlush(Logfile * lf);
#if STDC_HEADERS
extern void logfilePrintf(Logfile * lf, const char *fmt,...);
#else
extern void logfilePrintf(va_alist);
#endif