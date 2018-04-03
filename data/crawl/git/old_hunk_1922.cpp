	if ((args->depth > 0 || is_repository_shallow()) && !server_supports("shallow"))
		die("Server does not support shallow clients");
	if (server_supports("multi_ack_detailed")) {
		if (args->verbose)
			fprintf(stderr, "Server supports multi_ack_detailed\n");
		multi_ack = 2;
		if (server_supports("no-done")) {
			if (args->verbose)
				fprintf(stderr, "Server supports no-done\n");
			if (args->stateless_rpc)
				no_done = 1;
		}
	}
	else if (server_supports("multi_ack")) {
		if (args->verbose)
			fprintf(stderr, "Server supports multi_ack\n");
		multi_ack = 1;
	}
	if (server_supports("side-band-64k")) {
		if (args->verbose)
			fprintf(stderr, "Server supports side-band-64k\n");
		use_sideband = 2;
	}
	else if (server_supports("side-band")) {
		if (args->verbose)
			fprintf(stderr, "Server supports side-band\n");
		use_sideband = 1;
	}
	if (server_supports("allow-tip-sha1-in-want")) {
		if (args->verbose)
			fprintf(stderr, "Server supports allow-tip-sha1-in-want\n");
		allow_unadvertised_object_request |= ALLOW_TIP_SHA1;
	}
	if (server_supports("allow-reachable-sha1-in-want")) {
		if (args->verbose)
			fprintf(stderr, "Server supports allow-reachable-sha1-in-want\n");
		allow_unadvertised_object_request |= ALLOW_REACHABLE_SHA1;
	}
	if (!server_supports("thin-pack"))