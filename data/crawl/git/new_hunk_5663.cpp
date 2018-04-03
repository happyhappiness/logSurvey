#include "compat/bswap.h"

/* General helper functions */
extern NORETURN void usage(const char *err);
extern NORETURN void die(const char *err, ...) __attribute__((format (printf, 1, 2)));
extern NORETURN void die_errno(const char *err, ...) __attribute__((format (printf, 1, 2)));
extern int error(const char *err, ...) __attribute__((format (printf, 1, 2)));
extern void warning(const char *err, ...) __attribute__((format (printf, 1, 2)));

extern void set_die_routine(NORETURN void (*routine)(const char *err, va_list params));

extern int prefixcmp(const char *str, const char *prefix);
extern time_t tm_to_time_t(const struct tm *tm);
