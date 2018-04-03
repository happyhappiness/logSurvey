	}
	if (state->check_index)
		state->unsafe_paths = 0;
}

static int apply_all_patches(struct apply_state *state,
