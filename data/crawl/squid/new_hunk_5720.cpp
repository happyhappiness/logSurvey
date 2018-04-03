extern void fatal(const char *message);
#if STDC_HEADERS
extern void
fatalf(const char *fmt,...) PRINTF_FORMAT_ARG1;
#else
extern void fatalf();
#endif
