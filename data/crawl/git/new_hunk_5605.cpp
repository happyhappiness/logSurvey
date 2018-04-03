			if (args.verbose)
				fprintf(stderr, "got ack (%d) %s\n", ack,
					sha1_to_hex(result_sha1));
			if (ack == ACK)
				return 0;
			multi_ack = 1;
			continue;
