	va_end(params);
}

void usage(const char *err)
{
	usagef("%s", err);
}

void die(const char *err, ...)
{
	va_list params;

