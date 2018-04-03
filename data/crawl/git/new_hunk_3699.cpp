
	/*
	 * Warn when "git add pathspec..." was given without "-u" or "-A"
	 * and pathspec... covers a removed path.
	 */
	memset(&update_data, 0, sizeof(update_data));
	if (!take_worktree_changes && addremove_explicit < 0)
		update_data.warn_add_would_remove = 1;

	if (!take_worktree_changes && addremove_explicit < 0 && argc)
		/*
