		die("fetch-pack: unable to fork off %s", argv[0]);
	if (!pid) {
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		execv_git_cmd(argv);
		die("%s exec failed", argv[0]);
	}
	close(fd[0]);
	close(fd[1]);
	while (waitpid(pid, &status, 0) < 0) {
		if (errno != EINTR)
			die("waiting for %s: %s", argv[0], strerror(errno));
