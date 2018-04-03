
	paths[0] = NULL;
	diff_tree_setup_paths(paths, &diff_opts);
	diff_setup_done(&diff_opts);

	/* Try "find copies harder" on new path if requested;
	 * we do not want to use diffcore_rename() actually to
