		current_device = buf.st_dev;
	}
	for (;;) {
		gitfile_dir = read_gitfile_gently(DEFAULT_GIT_DIR_ENVIRONMENT);
		if (gitfile_dir) {
			if (set_git_dir(gitfile_dir))
				die("Repository setup failed");
			break;
		}
		if (is_git_directory(DEFAULT_GIT_DIR_ENVIRONMENT))
			break;
		if (is_git_directory(".")) {
			inside_git_dir = 1;