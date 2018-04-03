
	if (!option_bare) {
		junk_work_tree = work_tree;
		if (mkdir(work_tree, 0755))
			die("could not create work tree dir '%s'.", work_tree);
		set_git_work_tree(work_tree);
