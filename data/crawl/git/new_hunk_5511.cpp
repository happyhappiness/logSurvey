	fprintf(stderr, "%s%s\n", prefix, msg);
}

static NORETURN void usage_builtin(const char *err, va_list params)
{
	report("usage: ", err, params);
	exit(129);
}

