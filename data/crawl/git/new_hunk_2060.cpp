	size_t size = 0;

	if (strbuf_read(&buf, 0, 0) < 0)
		return error_errno("error while reading from stdin");

	s->should_munmap = 0;
	s->data = strbuf_detach(&buf, &size);