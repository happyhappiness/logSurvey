	}

	if (take_worktree_changes) {
		if (read_cache() < 0)
			die("index file corrupt");
		add_files_to_cache(verbose, prefix, argv + i);
		goto finish;
	}

