static void trace_write(struct trace_key *key, const void *buf, unsigned len)
{
	if (write_in_full(get_trace_fd(key), buf, len) < 0)
		fprintf(stderr, "%s: write error (%s)\n", err_msg, strerror(errno));
}

void trace_verbatim(struct trace_key *key, const void *buf, unsigned len)