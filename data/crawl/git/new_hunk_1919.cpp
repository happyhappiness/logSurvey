	while (flushes || multi_ack) {
		int ack = get_ack(fd[0], result_sha1);
		if (ack) {
			print_verbose(args, "got ack (%d) %s", ack,
				      sha1_to_hex(result_sha1));
			if (ack == ACK)
				return 0;
			multi_ack = 1;
