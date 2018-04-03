		write_shallow_commits(&req_buf, 1, NULL);
	if (args->depth > 0)
		packet_buf_write(&req_buf, "deepen %d", args->depth);
	if (args->deepen_since) {
		unsigned long max_age = approxidate(args->deepen_since);
		packet_buf_write(&req_buf, "deepen-since %lu", max_age);
	}
	packet_buf_flush(&req_buf);
	state_len = req_buf.len;

