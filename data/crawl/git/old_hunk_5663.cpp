#include "compat/bswap.h"

/* General helper functions */
extern void usage(const char *err) NORETURN;
extern void die(const char *err, ...) NORETURN __attribute__((format (printf, 1, 2)));
extern void die_errno(const char *err, ...) NORETURN __attribute__((format (printf, 1, 2)));
extern int error(const char *err, ...) __attribute__((format (printf, 1, 2)));
extern void warning(const char *err, ...) __attribute__((format (printf, 1, 2)));

extern void set_die_routine(void (*routine)(const char *err, va_list params) NORETURN);

extern int prefixcmp(const char *str, const char *prefix);
extern time_t tm_to_time_t(const struct tm *tm);
