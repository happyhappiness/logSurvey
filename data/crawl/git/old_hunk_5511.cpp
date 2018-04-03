	fprintf(stderr, "%s%s\n", prefix, msg);
}

static NORETURN void usage_builtin(const char *err)
{
	fprintf(stderr, "usage: %s\n", err);
	exit(129);
}

