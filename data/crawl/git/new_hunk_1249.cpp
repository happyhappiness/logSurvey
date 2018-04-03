	if (!list && !skipped_patch)
		die(_("unrecognized input"));

	if (state->whitespace_error && (state->ws_error_action == die_on_ws_error))
		state->apply = 0;

	state->update_index = state->check_index && state->apply;
	if (state->update_index && state->newfd < 0)
		state->newfd = hold_locked_index(state->lock_file, 1);

	if (state->check_index) {
		if (read_cache() < 0)
			die(_("unable to read index file"));
	}

	if ((state->check || state->apply) &&
	    check_patch_list(state, list) < 0 &&
	    !state->apply_with_reject)
		exit(1);

	if (state->apply && write_out_results(state, list)) {
		if (state->apply_with_reject)
			exit(1);
		/* with --3way, we still need to write the index out */
		return 1;
	}

	if (state->fake_ancestor)
		build_fake_ancestor(list, state->fake_ancestor);

	if (state->diffstat)
		stat_patch_list(state, list);

	if (state->numstat)
		numstat_patch_list(state, list);

	if (state->summary)
		summary_patch_list(list);

	free_patch_list(list);
	strbuf_release(&buf);
	string_list_clear(&state->fn_table, 0);
	return 0;
}

