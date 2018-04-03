	va_end(params);
}

void NORETURN die_errno(const char *fmt, ...)
{
	va_list params;
	char fmt_with_err[1024];