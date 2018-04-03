
	if (initialized)
		return;

	if (work_tree_config_is_bogus)
		die("unable to set up work tree using invalid config");

	work_tree = get_git_work_tree();
	git_dir = get_git_dir();
	if (!is_absolute_path(git_dir))
