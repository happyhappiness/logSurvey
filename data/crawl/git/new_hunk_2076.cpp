		pfd[1].events = POLLIN;
		if (poll(pfd, 2, -1) < 0) {
			if (errno != EINTR) {
				error_errno("poll failed resuming");
				sleep(1);
			}
			continue;