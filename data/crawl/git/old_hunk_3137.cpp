	unsigned char orig_head[GIT_SHA1_RAWSZ], curr_head[GIT_SHA1_RAWSZ];
	unsigned char rebase_fork_point[GIT_SHA1_RAWSZ];

	if (!getenv("_GIT_USE_BUILTIN_PULL")) {
		const char *path = mkpath("%s/git-pull", git_exec_path());

		if (sane_execvp(path, (char **)argv) < 0)
			die_errno("could not exec %s", path);
	}

	if (!getenv("GIT_REFLOG_ACTION"))
		set_reflog_message(argc, argv);
