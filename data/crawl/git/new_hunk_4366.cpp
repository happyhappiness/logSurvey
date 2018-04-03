static NORETURN void bad_object(unsigned long offset, const char *format,
		       ...) __attribute__((format (printf, 2, 3)));

static NORETURN void bad_object(unsigned long offset, const char *format, ...)
{
	va_list params;
	char buf[1024];
