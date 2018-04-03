
	paths[0] = NULL;
	diff_tree_setup_paths(paths, &diff_opts);
	if (diff_setup_done(&diff_opts) < 0)
		die("diff-setup");

	/* Try "find copies harder" on new path if requested;
	 * we do not want to use diffcore_rename() actually to
