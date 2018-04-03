	sb->buf[sb->len] = '\0';
}

void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len)
{
	strbuf_grow(sb, len);
	if (pos > sb->len)
		die("`pos' is too far after the end of the buffer");
	memmove(sb->buf + pos + len, sb->buf + pos, sb->len - pos);
	memcpy(sb->buf + pos, data, len);
	strbuf_setlen(sb, sb->len + len);
}

void strbuf_splice(struct strbuf *sb, size_t pos, size_t len,
				   const void *data, size_t dlen)
{
