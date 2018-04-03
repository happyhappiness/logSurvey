	struct pollfd *pfd;
	int i;

	if (pipe(child_handler_pipe) < 0)
		die ("Could not set up pipe for child handler");

	pfd = xcalloc(socknum + 1, sizeof(struct pollfd));

	for (i = 0; i < socknum; i++) {
		pfd[i].fd = socklist[i];
		pfd[i].events = POLLIN;
	}
	pfd[socknum].fd = child_handler_pipe[0];
	pfd[socknum].events = POLLIN;

	signal(SIGCHLD, child_handler);

	for (;;) {
		int i;

		if (poll(pfd, socknum + 1, -1) < 0) {
			if (errno != EINTR) {
				error("poll failed, resuming: %s",
				      strerror(errno));
				sleep(1);
			}
			continue;
		}
		if (pfd[socknum].revents & POLLIN) {
			read(child_handler_pipe[0], &i, 1);
			check_dead_children();
		}

		for (i = 0; i < socknum; i++) {