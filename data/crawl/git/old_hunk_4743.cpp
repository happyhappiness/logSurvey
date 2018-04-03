	else {
		work_tree = getenv("GIT_WORK_TREE");
		if (work_tree && !stat(work_tree, &buf))
			die("working tree '%s' already exists.", work_tree);
	}

	if (option_bare || work_tree)
