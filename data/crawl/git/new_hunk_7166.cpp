	newfd = hold_locked_index(&lock_file, 1);

	if (take_worktree_changes) {
		int flags = 0;
		const char **pathspec;
		if (read_cache() < 0)
			die("index file corrupt");
		pathspec = get_pathspec(prefix, argv);

		if (verbose)
			flags |= ADD_FILES_VERBOSE;

		exit_status = add_files_to_cache(prefix, pathspec, flags);
		goto finish;
	}

