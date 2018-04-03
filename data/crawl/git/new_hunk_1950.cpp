	}
	if (state->check_index)
		state->unsafe_paths = 0;
	if (!state->lock_file)
		die("BUG: state->lock_file should not be NULL");
}

static int apply_all_patches(struct apply_state *state,
