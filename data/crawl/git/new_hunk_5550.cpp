			}
			die("expected shallow/unshallow, got %s", line);
		}
	} else if (!args.stateless_rpc)
		send_request(fd[1], &req_buf);

	if (!args.stateless_rpc) {
		/* If we aren't using the stateless-rpc interface
		 * we don't need to retain the headers.
		 */
		strbuf_setlen(&req_buf, 0);
		state_len = 0;
	}

	flushes = 0;
	retval = -1;
	while ((sha1 = get_rev())) {
		packet_buf_write(&req_buf, "have %s\n", sha1_to_hex(sha1));
		if (args.verbose)
			fprintf(stderr, "have %s\n", sha1_to_hex(sha1));
		in_vain++;
		if (!(31 & ++count)) {
			int ack;

			packet_buf_flush(&req_buf);
			send_request(fd[1], &req_buf);
			strbuf_setlen(&req_buf, state_len);
			flushes++;

			/*
			 * We keep one window "ahead" of the other side, and
			 * will wait for an ACK only on the next one
			 */
			if (!args.stateless_rpc && count == 32)
				continue;

			consume_shallow_list(fd[0]);
			do {
				ack = get_ack(fd[0], result_sha1);
				if (args.verbose && ack)
