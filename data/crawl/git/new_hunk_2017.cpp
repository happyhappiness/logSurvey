
		if (ret < 0) {
			if (errno != EINTR) {
				error_errno("poll failed, resuming");
				sleep(1);
			}
			continue;