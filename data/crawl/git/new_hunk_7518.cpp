
	index_file = prepare_index(argc, argv, prefix);

	/* Set up everything for writing the commit object.  This includes
	   running hooks, writing the trees, and interacting with the user.  */
	if (!prepare_to_commit(index_file, prefix)) {
		rollback_index_files();
		return 1;
	}

	/*
	 * The commit object
	 */
