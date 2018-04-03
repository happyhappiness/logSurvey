	return 1;
}

static void trace_write(struct trace_key *key, const void *buf, unsigned len)
{
	if (write_in_full(get_trace_fd(key), buf, len) < 0)
		fprintf(stderr, "%s: write error (%s)\n", err_msg, strerror(errno));
}

void trace_verbatim(struct trace_key *key, const void *buf, unsigned len)
{
	if (!trace_want(key))
		return;
	trace_write(key, buf, len);
}

static void print_trace_line(struct trace_key *key, struct strbuf *buf)
{
	strbuf_complete_line(buf);
	trace_write(key, buf->buf, buf->len);
	strbuf_release(buf);
}
