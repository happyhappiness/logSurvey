
void trace_printf(const char *fmt, ...)
{
	char buf[8192];
	va_list ap;
	int fd, len, need_close = 0;

	fd = get_trace_fd(&need_close);
	if (!fd)
		return;

	va_start(ap, fmt);
	len = vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);
	if (len >= sizeof(buf))
		die("unreasonnable trace length");
	write_or_whine_pipe(fd, buf, len, err_msg);

	if (need_close)
		close(fd);
}

void trace_argv_printf(const char **argv, int count, const char *fmt, ...)
{
	char buf[8192];
	va_list ap;
	char *argv_str;
	size_t argv_len;
	int fd, len, need_close = 0;

	fd = get_trace_fd(&need_close);
	if (!fd)
		return;

	va_start(ap, fmt);
	len = vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);
	if (len >= sizeof(buf))
		die("unreasonnable trace length");

	/* Get the argv string. */
	argv_str = sq_quote_argv(argv, count);
	argv_len = strlen(argv_str);

	write_or_whine_pipe(fd, buf, len, err_msg);
	write_or_whine_pipe(fd, argv_str, argv_len, err_msg);
	write_or_whine_pipe(fd, "\n", 1, err_msg);

	free(argv_str);

	if (need_close)
		close(fd);