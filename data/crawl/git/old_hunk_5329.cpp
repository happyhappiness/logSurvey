	 *   etc.
	 */
	offset = len = strlen(cwd);
	for (;;) {
		gitfile_dir = read_gitfile_gently(DEFAULT_GIT_DIR_ENVIRONMENT);
		if (gitfile_dir) {
