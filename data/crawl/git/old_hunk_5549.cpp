	if (args.depth > 0)
		packet_buf_write(&req_buf, "deepen %d", args.depth);
	packet_buf_flush(&req_buf);

	safe_write(fd[1], req_buf.buf, req_buf.len);

	if (args.depth > 0) {
		char line[1024];
		unsigned char sha1[20];

		while (packet_read_line(fd[0], line, sizeof(line))) {
			if (!prefixcmp(line, "shallow ")) {
				if (get_sha1_hex(line + 8, sha1))
