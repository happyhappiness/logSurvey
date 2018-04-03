	 */
	xwrite(child_notifier, "", 1);
}

static NORETURN void die_child(const char *err, va_list params)
{
	vwritef(child_err, "fatal: ", err, params);
	exit(128);
}

static void error_child(const char *err, va_list params)
{
	vwritef(child_err, "error: ", err, params);
}
#endif

static inline void set_cloexec(int fd)
