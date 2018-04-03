			      const char *fmt, va_list args)
{
	struct strbuf buf = STRBUF_INIT;

	format_packet(&buf, fmt, args);
	if (write_in_full(fd, buf.buf, buf.len) < 0) {
		if (!gently) {
			check_pipe(errno);
			die_errno("packet write with format failed");
		}
		return error("packet write with format failed");
	}

	return 0;
}

void packet_write_fmt(int fd, const char *fmt, ...)
