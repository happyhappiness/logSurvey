	fputs("\n", stderr);
}

__attribute__((format (printf, 2, 3)))
static int objerror(struct object *obj, const char *err, ...)
{
	va_list params;
