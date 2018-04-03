
static void *read_patch_file(int fd, unsigned long *sizep)
{
	struct strbuf buf;

	strbuf_init(&buf);
	if (strbuf_read(&buf, fd) < 0)
		die("git-apply: read returned %s", strerror(errno));
	*sizep = buf.len;

	/*
	 * Make sure that we have some slop in the buffer
	 * so that we can do speculative "memcmp" etc, and
	 * see to it that it is NUL-filled.
	 */
	strbuf_grow(&buf, SLOP);
	memset(buf.buf + buf.len, 0, SLOP);
	return strbuf_detach(&buf);
}

static unsigned long linelen(const char *buffer, unsigned long size)
