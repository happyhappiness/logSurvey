		    base_path);

	if (inetd_mode) {
		struct sockaddr_storage ss;
		struct sockaddr *peer = (struct sockaddr *)&ss;
		socklen_t slen = sizeof(ss);

		if (!freopen("/dev/null", "w", stderr))
			die_errno("failed to redirect stderr to /dev/null");

		if (getpeername(0, peer, &slen))
			peer = NULL;

		return execute(peer);
	}

	if (detach) {
