		write_shallow_commits(&req_buf, 1, NULL);
	if (args->depth > 0)
		packet_buf_write(&req_buf, "deepen %d", args->depth);
	packet_buf_flush(&req_buf);
	state_len = req_buf.len;

