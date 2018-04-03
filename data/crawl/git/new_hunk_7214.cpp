		    GIT_WORK_TREE_ENVIRONMENT,
		    GIT_DIR_ENVIRONMENT);

	/*
	 * Set up the default .git directory contents
	 */
	if (!git_dir)
		git_dir = DEFAULT_GIT_DIR_ENVIRONMENT;

	if (is_bare_repository_cfg < 0)
		is_bare_repository_cfg = guess_repository_type(git_dir);

	if (!is_bare_repository_cfg) {
		if (git_dir) {
			const char *git_dir_parent = strrchr(git_dir, '/');
			if (git_dir_parent) {
				char *rel = xstrndup(git_dir, git_dir_parent - git_dir);
				git_work_tree_cfg = xstrdup(make_absolute_path(rel));
				free(rel);
			}
		}
		if (!git_work_tree_cfg) {
			git_work_tree_cfg = xcalloc(PATH_MAX, 1);
			if (!getcwd(git_work_tree_cfg, PATH_MAX))
				die ("Cannot access current working directory.");
		}
		if (access(get_git_work_tree(), X_OK))
			die ("Cannot access work tree '%s'",
			     get_git_work_tree());
	}

	set_git_dir(make_absolute_path(git_dir));

	return init_db(template_dir, flags);
}
