	sb->buf[sb->len] = '\0';
}

void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len) {
	strbuf_grow(sb, len);
	if (pos >= sb->len) {
		pos = sb->len;
	} else {
		memmove(sb->buf + pos + len, sb->buf + pos, sb->len - pos);
	}
	memcpy(sb->buf + pos, data, len);
	strbuf_setlen(sb, sb->len + len);
}

void strbuf_add(struct strbuf *sb, const void *data, size_t len) {
	strbuf_grow(sb, len);
	memcpy(sb->buf + sb->len, data, len);
	strbuf_setlen(sb, sb->len + len);
}

void strbuf_addf(struct strbuf *sb, const char *fmt, ...) {
	int len;
	va_list ap;

