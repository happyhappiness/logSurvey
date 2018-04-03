	die_routine = routine;
}

void usagef(const char *err, ...)
{
	va_list params;

	va_start(params, err);
	usage_routine(err, params);
	va_end(params);
}

void usage(const char *err)
{
	usagef("%s", err);
}

void die(const char *err, ...)