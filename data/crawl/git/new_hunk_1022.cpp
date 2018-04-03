	packet_trace(out->buf + orig_len + 4, n - 4, 1);
}

static int packet_write_fmt_1(int fd, int gently,
			      const char *fmt, va_list args)
{
	struct strbuf buf = STRBUF_INIT;
	ssize_t count;

	format_packet(&buf, fmt, args);
	count = write_in_full(fd, buf.buf, buf.len);
	if (count == buf.len)
		return 0;

	if (!gently) {
		check_pipe(errno);
		die_errno("packet write with format failed");
	}
	return error("packet write with format failed");
}

void packet_write_fmt(int fd, const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	packet_write_fmt_1(fd, 0, fmt, args);
	va_end(args);
}

int packet_write_fmt_gently(int fd, const char *fmt, ...)
{
	int status;
	va_list args;

	va_start(args, fmt);
	status = packet_write_fmt_1(fd, 1, fmt, args);
	va_end(args);
	return status;
}

void packet_buf_write(struct strbuf *buf, const char *fmt, ...)
