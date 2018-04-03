		socklen_t slen = sizeof(ss);

		if (!freopen("/dev/null", "w", stderr))
			die_errno("failed to redirect stderr to /dev/null");

		if (getpeername(0, peer, &slen))
			peer = NULL;
