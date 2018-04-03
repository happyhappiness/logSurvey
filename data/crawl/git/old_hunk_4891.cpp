	static char buffer[1024 + 1];
	const char *retval;

	if (PATH_MAX - 40 < strlen(gitdirenv))
		die("'$%s' too big", GIT_DIR_ENVIRONMENT);
	if (!is_git_directory(gitdirenv)) {
