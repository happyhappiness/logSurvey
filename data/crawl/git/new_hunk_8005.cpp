
			do {
				ack = get_ack(fd[0], result_sha1);
				if (args.verbose && ack)
					fprintf(stderr, "got ack %d %s\n", ack,
							sha1_to_hex(result_sha1));
				if (ack == 1) {
