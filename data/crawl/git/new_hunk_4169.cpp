		 * Must establish NOTES_MERGE_WORKTREE.
		 * Abort if NOTES_MERGE_WORKTREE already exists
		 */
		if (file_exists(git_path(NOTES_MERGE_WORKTREE)) &&
		    !is_empty_dir(git_path(NOTES_MERGE_WORKTREE))) {
			if (advice_resolve_conflict)
				die("You have not concluded your previous "
				    "notes merge (%s exists).\nPlease, use "
