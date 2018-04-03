static const char err_msg[] = "Could not trace into fd given by "
	"GIT_TRACE environment variable";

void trace_printf(const char *format, ...)
{
	char *trace_str;
	va_list rest;
	int need_close = 0;
	int fd = get_trace_fd(&need_close);

	if (!fd)
		return;

	va_start(rest, format);
	nfvasprintf(&trace_str, format, rest);
	va_end(rest);

	write_or_whine_pipe(fd, trace_str, strlen(trace_str), err_msg);

	free(trace_str);

	if (need_close)
		close(fd);
}

void trace_argv_printf(const char **argv, int count, const char *format, ...)
{
	char *argv_str, *format_str, *trace_str;
	size_t argv_len, format_len, trace_len;
	va_list rest;
	int need_close = 0;
	int fd = get_trace_fd(&need_close);

	if (!fd)
		return;

	/* Get the argv string. */
	argv_str = sq_quote_argv(argv, count);
	argv_len = strlen(argv_str);

	/* Get the formated string. */
	va_start(rest, format);
	nfvasprintf(&format_str, format, rest);
	va_end(rest);

	/* Allocate buffer for trace string. */
	format_len = strlen(format_str);
	trace_len = argv_len + format_len + 1; /* + 1 for \n */
	trace_str = xmalloc(trace_len + 1);

	/* Copy everything into the trace string. */
	strncpy(trace_str, format_str, format_len);
	strncpy(trace_str + format_len, argv_str, argv_len);
	strcpy(trace_str + trace_len - 1, "\n");

	write_or_whine_pipe(fd, trace_str, trace_len, err_msg);

	free(argv_str);
	free(format_str);
	free(trace_str);

	if (need_close)
		close(fd);