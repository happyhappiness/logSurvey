
	if (is_repository_shallow() && !server_supports("shallow"))
		die("Server does not support shallow clients");
	if (server_supports("multi_ack")) {
		if (args.verbose)
			fprintf(stderr, "Server supports multi_ack\n");
		multi_ack = 1;