	packet_trace(out->buf + orig_len + 4, n - 4, 1);
}

void packet_write(int fd, const char *fmt, ...)
{
	static struct strbuf buf = STRBUF_INIT;
	va_list args;
