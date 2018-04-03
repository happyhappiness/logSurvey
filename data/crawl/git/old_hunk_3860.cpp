	va_start(args, fmt);
	n = format_packet(fmt, args);
	va_end(args);
	safe_write(fd, buffer, n);
}

void packet_buf_write(struct strbuf *buf, const char *fmt, ...)
