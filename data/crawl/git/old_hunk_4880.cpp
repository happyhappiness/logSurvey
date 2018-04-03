		git_dir = make_absolute_path(git_dir);
	if (!work_tree || chdir(work_tree))
		die("This operation must be run in a work tree");
	set_git_dir(make_relative_path(git_dir, work_tree));
	initialized = 1;
}
