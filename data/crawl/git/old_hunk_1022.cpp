	packet_trace(out->buf + orig_len + 4, n - 4, 1);
}

void packet_write_fmt(int fd, const char *fmt, ...)
{
	static struct strbuf buf = STRBUF_INIT;
	va_list args;

	strbuf_reset(&buf);
	va_start(args, fmt);
	format_packet(&buf, fmt, args);
	va_end(args);
	write_or_die(fd, buf.buf, buf.len);
}

void packet_buf_write(struct strbuf *buf, const char *fmt, ...)
