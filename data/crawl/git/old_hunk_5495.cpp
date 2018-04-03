	fputs("\n", stderr);
}

static int objerror(struct object *obj, const char *err, ...)
{
	va_list params;
