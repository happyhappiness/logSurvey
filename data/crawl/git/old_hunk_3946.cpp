			die(_("Could not write new index file."));
	}

	/* Any resets update HEAD to the head being switched to,
	 * saving the previous head in ORIG_HEAD before. */
	update_ref_status = update_refs(rev, sha1);

	if (reset_type == HARD && !update_ref_status && !quiet)
		print_new_head_line(commit);

	remove_branch_state();

	return update_ref_status;
}