		struct sockaddr *peer = (struct sockaddr *)&ss;
		socklen_t slen = sizeof(ss);

		freopen("/dev/null", "w", stderr);

		if (getpeername(0, peer, &slen))
			peer = NULL;