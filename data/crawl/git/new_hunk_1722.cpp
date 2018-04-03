{
	va_list params;
	struct strbuf sb = STRBUF_INIT;
	int fd = xopen(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);

	va_start(params, fmt);
	strbuf_vaddf(&sb, fmt, params);