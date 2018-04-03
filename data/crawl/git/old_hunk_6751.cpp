	if (!option_bare) {
		junk_work_tree = work_tree;
		if (safe_create_leading_directories_const(work_tree) < 0)
			die("could not create leading directories of '%s'",
					work_tree);
		if (mkdir(work_tree, 0755))
			die("could not create work tree dir '%s'.", work_tree);
		set_git_work_tree(work_tree);
	}
	junk_git_dir = git_dir;
