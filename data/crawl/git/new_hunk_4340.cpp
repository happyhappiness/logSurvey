		if (args.verbose)
			fprintf(stderr, "Server supports multi_ack_detailed\n");
		multi_ack = 2;
		if (server_supports("no-done")) {
			if (args.verbose)
				fprintf(stderr, "Server supports no-done\n");
			no_done = 1;
		}
	}
	else if (server_supports("multi_ack")) {
		if (args.verbose)
