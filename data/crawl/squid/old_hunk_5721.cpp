extern void logfileFlush(Logfile * lf);
#if STDC_HEADERS
extern void
logfilePrintf(Logfile * lf, const char *fmt,...) PRINTF_FORMAT_ARG(2);
#else
extern void logfilePrintf(va_alist);
#endif