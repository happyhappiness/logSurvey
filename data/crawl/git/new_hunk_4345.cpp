		if (args.verbose)
			fprintf(stderr, "Server supports multi_ack_detailed\n");
		multi_ack = 2;
	}
	else if (server_supports("multi_ack")) {
		if (args.verbose)