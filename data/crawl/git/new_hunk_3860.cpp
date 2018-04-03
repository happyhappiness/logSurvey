	va_start(args, fmt);
	n = format_packet(fmt, args);
	va_end(args);
	write_or_die(fd, buffer, n);
}

void packet_buf_write(struct strbuf *buf, const char *fmt, ...)
