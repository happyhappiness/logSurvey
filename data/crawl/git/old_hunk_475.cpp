	git_dir = getenv(GIT_DIR_ENVIRONMENT);
	if (!git_dir) {
		if (!startup_info->have_repository)
			die("BUG: setup_git_env called without repository");
		git_dir = DEFAULT_GIT_DIR_ENVIRONMENT;
	}
	gitfile = read_gitfile(git_dir);
