
	if (reset_type == HARD && !update_ref_status && !quiet)
		print_new_head_line(commit);

	remove_branch_state();
