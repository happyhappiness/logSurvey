	return status;
}

void packet_buf_write(struct strbuf *buf, const char *fmt, ...)
{
	va_list args;