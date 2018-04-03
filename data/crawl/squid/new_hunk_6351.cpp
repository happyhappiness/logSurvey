

extern const char *getMyHostname(void);
extern const char *uniqueHostname(void);
extern void safeunlink(const char *path, int quiet);
extern void death(int sig);
extern void fatal(const char *message);
