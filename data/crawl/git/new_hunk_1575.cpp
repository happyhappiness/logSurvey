	if (state->update_index && state->newfd < 0)
		state->newfd = hold_locked_index(state->lock_file, 1);

	if (state->check_index && read_cache() < 0) {
		error(_("unable to read index file"));
		res = -128;
		goto end;
	}

	if ((state->check || state->apply) &&
	    check_patch_list(state, list) < 0 &&
	    !state->apply_with_reject) {
		res = -1;
		goto end;
	}

	if (state->apply && write_out_results(state, list)) {
		/* with --3way, we still need to write the index out */
		res = state->apply_with_reject ? -1 : 1;
		goto end;
	}

	if (state->fake_ancestor)
