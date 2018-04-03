		exit(0);
	}

	if (pipe(pu_pipe) < 0)
		die("git-upload-pack: unable to create pipe");
	if (pipe(pe_pipe) < 0)
		die("git-upload-pack: unable to create pipe");
	pid_pack_objects = fork();
	if (pid_pack_objects < 0) {
		/* daemon sets things up to ignore TERM */
		kill(pid_rev_list, SIGKILL);
		die("git-upload-pack: unable to fork git-pack-objects");
	}
	if (!pid_pack_objects) {
		const char *argv[10];
		int i = 0;

		dup2(lp_pipe[0], 0);
		dup2(pu_pipe[1], 1);
		dup2(pe_pipe[1], 2);

		close(lp_pipe[0]);
		close(lp_pipe[1]);
		close(pu_pipe[0]);
		close(pu_pipe[1]);
		close(pe_pipe[0]);
		close(pe_pipe[1]);

		argv[i++] = "pack-objects";
		argv[i++] = "--stdout";
		if (!no_progress)
			argv[i++] = "--progress";
		if (use_ofs_delta)
			argv[i++] = "--delta-base-offset";
		argv[i++] = NULL;

		execv_git_cmd(argv);
		kill(pid_rev_list, SIGKILL);
		die("git-upload-pack: unable to exec git-pack-objects");
	}

	close(lp_pipe[0]);
	close(lp_pipe[1]);

	/* We read from pe_pipe[0] to capture stderr output for
	 * progress bar, and pu_pipe[0] to capture the pack data.
	 */
	close(pe_pipe[1]);
	close(pu_pipe[1]);

	while (1) {
		const char *who;
