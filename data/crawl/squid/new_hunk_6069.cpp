extern void *leakFreeFL(void *, const char *, int);
#endif

/* logfile.c */
extern Logfile *logfileOpen(const char *path, size_t bufsz);
extern void logfileClose(Logfile * lf);
extern void logfileRotate(Logfile * lf);
extern void logfileWrite(Logfile * lf, void *buf, size_t len);
extern void logfileFlush(Logfile * lf);
#if STDC_HEADERS
extern void logfilePrintf(Logfile * lf, const char *fmt,...);
#else
extern void logfilePrintf(va_alist);
#endif

/*
 * prototypes for system functions missing from system includes
 */
