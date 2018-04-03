	qsort(sought, nr_sought, sizeof(*sought), cmp_ref_by_name);

	if ((args->depth > 0 || is_repository_shallow()) && !server_supports("shallow"))
		die("Server does not support shallow clients");
	if (server_supports("multi_ack_detailed")) {
		print_verbose(args, "Server supports multi_ack_detailed");
		multi_ack = 2;
		if (server_supports("no-done")) {
			print_verbose(args, "Server supports no-done");
			if (args->stateless_rpc)
				no_done = 1;
		}
	}
	else if (server_supports("multi_ack")) {
		print_verbose(args, "Server supports multi_ack");
		multi_ack = 1;
	}
	if (server_supports("side-band-64k")) {
		print_verbose(args, "Server supports side-band-64k");
		use_sideband = 2;
	}
	else if (server_supports("side-band")) {
		print_verbose(args, "Server supports side-band");
		use_sideband = 1;
	}
	if (server_supports("allow-tip-sha1-in-want")) {
		print_verbose(args, "Server supports allow-tip-sha1-in-want");
		allow_unadvertised_object_request |= ALLOW_TIP_SHA1;
	}
	if (server_supports("allow-reachable-sha1-in-want")) {
		print_verbose(args, "Server supports allow-reachable-sha1-in-want");
		allow_unadvertised_object_request |= ALLOW_REACHABLE_SHA1;
	}
	if (!server_supports("thin-pack"))
