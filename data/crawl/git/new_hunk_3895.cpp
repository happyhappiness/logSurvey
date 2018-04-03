
/*
 * Let callers be aware of the constant return value; this can help
 * gcc with -Wuninitialized analysis. We restrict this trick to gcc, though,
 * because some compilers may not support variadic macros. Since we're only
 * trying to help gcc, anyway, it's OK; other compilers will fall back to
 * using the function as usual.
 */
#ifdef __GNUC__
#define error(...) (error(__VA_ARGS__), -1)
#endif

extern void set_die_routine(NORETURN_PTR void (*routine)(const char *err, va_list params));