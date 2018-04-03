extern void safeunlink(const char *path, int quiet);
extern void death(int sig);
extern void fatal(const char *message);
#ifdef __STDC__
extern void fatalf(const char *fmt,...);
#else
extern void fatalf();
#endif
extern void fatal_dump(const char *message);
extern void sigusr2_handle(int sig);
extern void sig_child(int sig);
