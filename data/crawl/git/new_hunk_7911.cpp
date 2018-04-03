		exit(0);
	}

	/* writable pipe end must not be inherited by pack_objects */
	close(lp_pipe[1]);

	argv[arg++] = "pack-objects";
	argv[arg++] = "--stdout";
	if (!no_progress)
		argv[arg++] = "--progress";
	if (use_ofs_delta)
		argv[arg++] = "--delta-base-offset";
	argv[arg++] = NULL;

	memset(&pack_objects, 0, sizeof(pack_objects));
	pack_objects.in = lp_pipe[0];	/* start_command closes it */
	pack_objects.out = -1;
	pack_objects.err = -1;
	pack_objects.git_cmd = 1;
	pack_objects.argv = argv;
	if (start_command(&pack_objects)) {
		/* daemon sets things up to ignore TERM */
		kill(pid_rev_list, SIGKILL);
		die("git-upload-pack: unable to fork git-pack-objects");
	}

	/* We read from pack_objects.err to capture stderr output for
	 * progress bar, and pack_objects.out to capture the pack data.
	 */

	while (1) {
		const char *who;
