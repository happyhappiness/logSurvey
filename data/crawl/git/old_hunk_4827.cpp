
void trace_argv_printf(const char **argv, const char *fmt, ...)
{
	struct strbuf buf;
	va_list ap;
	int fd, len, need_close = 0;

	fd = get_trace_fd(&need_close);
	if (!fd)
		return;

	set_try_to_free_routine(NULL);	/* is never reset */
	strbuf_init(&buf, 64);
	va_start(ap, fmt);
	len = vsnprintf(buf.buf, strbuf_avail(&buf), fmt, ap);
	va_end(ap);
	if (len >= strbuf_avail(&buf)) {
		strbuf_grow(&buf, len - strbuf_avail(&buf) + 128);
		va_start(ap, fmt);
		len = vsnprintf(buf.buf, strbuf_avail(&buf), fmt, ap);
		va_end(ap);
		if (len >= strbuf_avail(&buf))
			die("broken vsnprintf");
	}
	strbuf_setlen(&buf, len);

	sq_quote_argv(&buf, argv, 0);
	strbuf_addch(&buf, '\n');