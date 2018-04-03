	    (send_all && args.send_mirror))
		usage(send_pack_usage);

	if (is_repository_shallow())
		die("attempt to push from a shallow repository");

	if (remote_name) {
