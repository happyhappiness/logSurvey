
	if (!getcwd(cwd, sizeof(cwd)-1))
		die("Unable to read current working directory");

	/*
	 * Test in the following order (relative to the cwd):
	 * - .git/
	 * - ./ (bare)
	 * - ../.git/
	 * - ../ (bare)
	 * - ../../.git/
	 *   etc.
	 */
	offset = len = strlen(cwd);
	for (;;) {
		if (is_git_directory(DEFAULT_GIT_DIR_ENVIRONMENT))
			break;
		if (is_git_directory(".")) {
			inside_git_dir = 1;
			if (!work_tree_env)
				inside_work_tree = 0;
			setenv(GIT_DIR_ENVIRONMENT, ".", 1);
			return NULL;
		}
		chdir("..");
		do {
			if (!offset) {
				if (nongit_ok) {
					if (chdir(cwd))
						die("Cannot come back to cwd");
					*nongit_ok = 1;
					return NULL;
				}
				die("Not a git repository");
			}
		} while (cwd[--offset] != '/');
	}

	inside_git_dir = 0;
	if (!work_tree_env)
		inside_work_tree = 1;
	git_work_tree_cfg = xstrndup(cwd, offset);
	if (offset == len)
		return NULL;

	/* Make "offset" point to past the '/', and add a '/' at the end */
	offset++;
	cwd[len++] = '/';
	cwd[len] = 0;
	return cwd + offset;
}

int git_config_perm(const char *var, const char *value)
