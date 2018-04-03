
extern int optbug(const struct option *opt, const char *reason);
extern int opterror(const struct option *opt, const char *reason, int flags);
#ifdef __GNUC__
#define opterror(o,r,f) (opterror((o),(r),(f)), -1)
#endif

/*----- incremental advanced APIs -----*/

enum {