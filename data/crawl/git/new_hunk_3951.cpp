
	if (reset_type == HARD && !update_ref_status && !quiet)
		print_new_head_line(commit);
	else if (reset_type == MIXED) { /* Report what has not been updated. */
		struct lock_file *index_lock = xcalloc(1, sizeof(struct lock_file));
		int fd = hold_locked_index(index_lock, 1);
		update_index_refresh(
			quiet ? REFRESH_QUIET : REFRESH_IN_PORCELAIN);
		if (write_cache(fd, active_cache, active_nr) ||
		    commit_locked_index(index_lock))
			error("Could not refresh index");
	}

	remove_branch_state();
