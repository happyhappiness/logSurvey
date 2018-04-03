			consume_shallow_list(args, fd[0]);
			do {
				ack = get_ack(fd[0], result_sha1);
				if (ack)
					print_verbose(args, "got ack %d %s", ack,
						      sha1_to_hex(result_sha1));
				switch (ack) {
				case ACK:
					flushes = 0;
