	use(sizeof(struct pack_header));
}

static NORETURN void bad_object(unsigned long offset, const char *format,
		       ...) __attribute__((format (printf, 2, 3)));

static void bad_object(unsigned long offset, const char *format, ...)
{
