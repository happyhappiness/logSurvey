		git_dir = make_absolute_path(git_dir);
	if (!work_tree || chdir(work_tree))
		die("This operation must be run in a work tree");

	/*
	 * Make sure subsequent git processes find correct worktree
	 * if $GIT_WORK_TREE is set relative
	 */
	if (getenv(GIT_WORK_TREE_ENVIRONMENT))
		setenv(GIT_WORK_TREE_ENVIRONMENT, ".", 1);

	set_git_dir(make_relative_path(git_dir, work_tree));
	initialized = 1;
}
