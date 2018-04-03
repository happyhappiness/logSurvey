	signal(SIGCHLD, SIG_DFL);

	protocol = parse_connect_url(url, &host, &port, &path);

	if (protocol == PROTO_GIT) {
		/* These underlying connection commands die() if they
