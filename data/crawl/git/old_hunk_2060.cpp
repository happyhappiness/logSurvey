	size_t size = 0;

	if (strbuf_read(&buf, 0, 0) < 0)
		return error("error while reading from stdin %s",
				     strerror(errno));

	s->should_munmap = 0;
	s->data = strbuf_detach(&buf, &size);