		    base_path);

	if (inetd_mode) {
		if (!freopen("/dev/null", "w", stderr))
			die_errno("failed to redirect stderr to /dev/null");
	}

	if (inetd_mode || serve_mode) {
		struct sockaddr_storage ss;
		struct sockaddr *peer = (struct sockaddr *)&ss;
		socklen_t slen = sizeof(ss);

		if (getpeername(0, peer, &slen))
			return execute(NULL);
		else
			return execute(peer);
	}

	if (detach) {
