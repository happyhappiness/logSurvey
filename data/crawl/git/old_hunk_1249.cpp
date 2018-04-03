	if (!list && !skipped_patch)
		die(_("unrecognized input"));

	if (whitespace_error && (ws_error_action == die_on_ws_error))
		apply = 0;

	update_index = check_index && apply;
	if (update_index && newfd < 0)
		newfd = hold_locked_index(&lock_file, 1);

	if (check_index) {
		if (read_cache() < 0)
			die(_("unable to read index file"));
	}

	if ((check || apply) &&
	    check_patch_list(list) < 0 &&
	    !apply_with_reject)
		exit(1);

	if (apply && write_out_results(list)) {
		if (apply_with_reject)
			exit(1);
		/* with --3way, we still need to write the index out */
		return 1;
	}

	if (fake_ancestor)
		build_fake_ancestor(list, fake_ancestor);

	if (diffstat)
		stat_patch_list(list);

	if (numstat)
		numstat_patch_list(list);

	if (summary)
		summary_patch_list(list);

	free_patch_list(list);
	strbuf_release(&buf);
	string_list_clear(&fn_table, 0);
	return 0;
}

