
	if (reset_type == HARD && !update_ref_status && !quiet)
		print_new_head_line(commit);
	else if (reset_type == MIXED) /* Report what has not been updated. */
		update_index_refresh(0, NULL,
				quiet ? REFRESH_QUIET : REFRESH_IN_PORCELAIN);

	remove_branch_state();
