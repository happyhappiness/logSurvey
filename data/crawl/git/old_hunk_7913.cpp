		*av++ = hdr_arg;
	*av++ = NULL;

	pid = fork();
	if (pid < 0)
		die("fetch-pack: unable to fork off %s", argv[0]);
	if (!pid) {
		dup2(fd[0], 0);
		if (do_keep && pack_lockfile) {
			dup2(keep_pipe[1], 1);
			close(keep_pipe[0]);
			close(keep_pipe[1]);
		}
		close(fd[0]);
		close(fd[1]);
		execv_git_cmd(argv);
		die("%s exec failed", argv[0]);
	}
	close(fd[0]);
	close(fd[1]);
	if (do_keep && pack_lockfile) {
		close(keep_pipe[1]);
		*pack_lockfile = index_pack_lockfile(keep_pipe[0]);
		close(keep_pipe[0]);
	}
	while (waitpid(pid, &status, 0) < 0) {
		if (errno != EINTR)
			die("waiting for %s: %s", argv[0], strerror(errno));
	}
	if (WIFEXITED(status)) {
		int code = WEXITSTATUS(status);
		if (code)
			die("%s died with error code %d", argv[0], code);
		return 0;
	}
	if (WIFSIGNALED(status)) {
		int sig = WTERMSIG(status);
		die("%s died of signal %d", argv[0], sig);
	}
	die("%s died of unnatural causes %d", argv[0], status);
}

static struct ref *do_fetch_pack(int fd[2],