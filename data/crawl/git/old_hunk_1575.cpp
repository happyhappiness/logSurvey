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
