	return retval;
}

static int cwd_contains_git_dir(const char **gitfile_dirp)
{
	const char *gitfile_dir = read_gitfile_gently(DEFAULT_GIT_DIR_ENVIRONMENT);
	*gitfile_dirp = gitfile_dir;
	if (gitfile_dir) {
		if (set_git_dir(gitfile_dir))
			die("Repository setup failed");
		return 1;
	}
	if (is_git_directory(DEFAULT_GIT_DIR_ENVIRONMENT)) {
		*gitfile_dirp = DEFAULT_GIT_DIR_ENVIRONMENT;
		return 1;
	}
	return 0;
}

static const char *setup_discovered_git_dir(const char *work_tree_env,
					    const char *gitdir,
					    int offset, int len,
					    char *cwd, int *nongit_ok)
{
	int root_len;
	char *work_tree;

	inside_git_dir = 0;
	if (!work_tree_env)
		inside_work_tree = 1;
	root_len = offset_1st_component(cwd);
	work_tree = xstrndup(cwd, offset > root_len ? offset : root_len);
	set_git_work_tree(work_tree);
	free(work_tree);
	if (check_repository_format_gently(gitdir, nongit_ok))
		return NULL;
	if (offset == len)
		return NULL;

