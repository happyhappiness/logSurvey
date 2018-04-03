extern void safeunlink(const char *path, int quiet);
extern void death(int sig);
extern void fatal(const char *message);
extern void fatal_dump(const char *message);
extern void sigusr2_handle(int sig);
extern void sig_child(int sig);
