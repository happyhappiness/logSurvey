	if (!option_bare) {
		junk_work_tree = work_tree;
		if (safe_create_leading_directories_const(work_tree) < 0)
			die_errno("could not create leading directories of '%s'",
				  work_tree);
		if (!dest_exists && mkdir(work_tree, 0755))
			die_errno("could not create work tree dir '%s'.",
				  work_tree);
		set_git_work_tree(work_tree);
	}
