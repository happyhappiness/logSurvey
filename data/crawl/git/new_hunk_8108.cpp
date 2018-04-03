
static int populate_from_stdin(struct diff_filespec *s)
{
	struct strbuf buf;

	strbuf_init(&buf);
	if (strbuf_read(&buf, 0) < 0)
		return error("error while reading from stdin %s",
				     strerror(errno));

	s->should_munmap = 0;
	s->size = buf.len;
	s->data = strbuf_detach(&buf);
	s->should_free = 1;
	return 0;
}