			}
			die("expected shallow/unshallow, got %s", line);
		}
	}

	flushes = 0;
	retval = -1;
	while ((sha1 = get_rev())) {
		packet_write(fd[1], "have %s\n", sha1_to_hex(sha1));
		if (args.verbose)
			fprintf(stderr, "have %s\n", sha1_to_hex(sha1));
		in_vain++;
		if (!(31 & ++count)) {
			int ack;

			packet_flush(fd[1]);
			flushes++;

			/*
			 * We keep one window "ahead" of the other side, and
			 * will wait for an ACK only on the next one
			 */
			if (count == 32)
				continue;

			do {
				ack = get_ack(fd[0], result_sha1);
				if (args.verbose && ack)
