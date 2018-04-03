	if (is_repository_shallow() && !server_supports("shallow"))
		die("Server does not support shallow clients");
	if (server_supports("multi_ack")) {
		if (args.verbose)
			fprintf(stderr, "Server supports multi_ack\n");
		multi_ack = 1;
	}
	if (server_supports("side-band-64k")) {
		if (args.verbose)
			fprintf(stderr, "Server supports side-band-64k\n");
		use_sideband = 2;
	}
	else if (server_supports("side-band")) {
		if (args.verbose)
			fprintf(stderr, "Server supports side-band\n");
		use_sideband = 1;
	}
