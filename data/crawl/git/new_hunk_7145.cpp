
	newfd = hold_locked_index(&lock_file, 1);

	flags = ((verbose ? ADD_CACHE_VERBOSE : 0) |
		 (show_only ? ADD_CACHE_PRETEND : 0));

	if (take_worktree_changes) {
		const char **pathspec;
		if (read_cache() < 0)
			die("index file corrupt");
		pathspec = get_pathspec(prefix, argv);
