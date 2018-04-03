#include "cache.h"
#include "strbuf.h"

void strbuf_init(struct strbuf *sb, size_t hint)
{
	memset(sb, 0, sizeof(*sb));
	if (hint)
		strbuf_grow(sb, hint);
}

void strbuf_release(struct strbuf *sb)
{
	free(sb->buf);
	memset(sb, 0, sizeof(*sb));
}

void strbuf_reset(struct strbuf *sb)
{
	if (sb->len)
		strbuf_setlen(sb, 0);
	sb->eof = 0;
}

char *strbuf_detach(struct strbuf *sb)
{
	char *res = sb->buf;
	strbuf_init(sb, 0);
	return res;
}

void strbuf_attach(struct strbuf *sb, void *buf, size_t len, size_t alloc)
{
	strbuf_release(sb);
	sb->buf   = buf;
	sb->len   = len;
	sb->alloc = alloc;
	strbuf_grow(sb, 0);
	sb->buf[sb->len] = '\0';
}

void strbuf_grow(struct strbuf *sb, size_t extra)
{
	if (sb->len + extra + 1 <= sb->len)
		die("you want to use way too much memory");
	ALLOC_GROW(sb->buf, sb->len + extra + 1, sb->alloc);
