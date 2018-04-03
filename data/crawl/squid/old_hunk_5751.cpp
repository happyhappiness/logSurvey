extern void death(int sig);
extern void fatal(const char *message);
#if STDC_HEADERS
extern void fatalf(const char *fmt,...);
#else
extern void fatalf();
#endif
