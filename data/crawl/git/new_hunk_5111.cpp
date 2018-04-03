	 * validation.
	 */
	gitdirenv = getenv(GIT_DIR_ENVIRONMENT);
	if (gitdirenv)
		return setup_explicit_git_dir(gitdirenv, work_tree_env, nongit_ok);

	if (!getcwd(cwd, sizeof(cwd)-1))
		die_errno("Unable to read current working directory");