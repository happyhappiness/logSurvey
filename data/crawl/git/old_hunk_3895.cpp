
/*
 * Let callers be aware of the constant return value; this can help
 * gcc with -Wuninitialized analysis. We have to restrict this trick to
 * gcc, though, because of the variadic macro and the magic ## comma pasting
 * behavior. But since we're only trying to help gcc, anyway, it's OK; other
 * compilers will fall back to using the function as usual.
 */
#ifdef __GNUC__
#define error(fmt, ...) (error((fmt), ##__VA_ARGS__), -1)
#endif

extern void set_die_routine(NORETURN_PTR void (*routine)(const char *err, va_list params));