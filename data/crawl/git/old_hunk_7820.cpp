	pack_objects.git_cmd = 1;
	pack_objects.argv = argv;

	if (start_command(&pack_objects)) {
		/* daemon sets things up to ignore TERM */
		kill(rev_list.pid, SIGKILL);
		die("git-upload-pack: unable to fork git-pack-objects");
	}

	/* We read from pack_objects.err to capture stderr output for
	 * progress bar, and pack_objects.out to capture the pack data.
	 */

	while (1) {
		const char *who;
		struct pollfd pfd[2];
		pid_t pid;
		int status;
		ssize_t sz;
		int pe, pu, pollsize;

		reset_timeout();
