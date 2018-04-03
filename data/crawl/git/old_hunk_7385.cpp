	if (strict_paths && (!ok_paths || !*ok_paths))
		die("option --strict-paths requires a whitelist");

	if (inetd_mode) {
		struct sockaddr_storage ss;
		struct sockaddr *peer = (struct sockaddr *)&ss;