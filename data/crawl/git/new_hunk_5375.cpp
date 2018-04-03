
static NORETURN void usage_builtin(const char *err, va_list params)
{
	vreportf("usage: ", err, params);
	exit(129);
}

static NORETURN void die_builtin(const char *err, va_list params)
{
	vreportf("fatal: ", err, params);
	exit(128);
}

static void error_builtin(const char *err, va_list params)
{
	vreportf("error: ", err, params);
}

static void warn_builtin(const char *warn, va_list params)
{
	vreportf("warning: ", warn, params);
}

/* If we are in a dlopen()ed .so write to a global variable would segfault