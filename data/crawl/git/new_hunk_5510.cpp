
/* General helper functions */
extern NORETURN void usage(const char *err);
extern NORETURN void usagef(const char *err, ...) __attribute__((format (printf, 1, 2)));
extern NORETURN void die(const char *err, ...) __attribute__((format (printf, 1, 2)));
extern NORETURN void die_errno(const char *err, ...) __attribute__((format (printf, 1, 2)));
extern int error(const char *err, ...) __attribute__((format (printf, 1, 2)));
