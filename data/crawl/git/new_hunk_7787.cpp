	int len;
	va_list ap;

	if (!strbuf_avail(sb))
		strbuf_grow(sb, 64);
	va_start(ap, fmt);
	len = vsnprintf(sb->buf + sb->len, sb->alloc - sb->len, fmt, ap);
	va_end(ap);
	if (len < 0)
		die("your vsnprintf is broken");
	if (len > strbuf_avail(sb)) {
		strbuf_grow(sb, len);
		va_start(ap, fmt);
