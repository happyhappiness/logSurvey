{
	va_list params;
	struct strbuf sb = STRBUF_INIT;
	int fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		die_errno(_("could not open %s for writing"), path);

	va_start(params, fmt);
	strbuf_vaddf(&sb, fmt, params);