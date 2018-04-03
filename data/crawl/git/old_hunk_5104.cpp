	 */
	offset = len = strlen(cwd);
	one_filesystem = !git_env_bool("GIT_DISCOVERY_ACROSS_FILESYSTEM", 0);
	if (one_filesystem) {
		if (stat(".", &buf))
			die_errno("failed to stat '.'");
		current_device = buf.st_dev;
	}
	for (;;) {
		if (cwd_contains_git_dir(&gitfile_dir))
			break;
