	newfd = hold_locked_index(&lock_file, 1);

	if (take_worktree_changes) {
		const char **pathspec;
		if (read_cache() < 0)
			die("index file corrupt");
		pathspec = get_pathspec(prefix, argv);
		add_files_to_cache(verbose, prefix, pathspec);
		goto finish;
	}

