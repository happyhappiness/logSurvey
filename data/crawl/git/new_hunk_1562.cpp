	return 0;
}

static int check_apply_state(struct apply_state *state, int force_apply)
{
	int is_not_gitdir = !startup_info->have_repository;

	if (state->apply_with_reject && state->threeway)
		return error("--reject and --3way cannot be used together.");
	if (state->cached && state->threeway)
		return error("--cached and --3way cannot be used together.");
	if (state->threeway) {
		if (is_not_gitdir)
			return error(_("--3way outside a repository"));
		state->check_index = 1;
	}
	if (state->apply_with_reject)
		state->apply = state->apply_verbosely = 1;
	if (!force_apply && (state->diffstat || state->numstat || state->summary || state->check || state->fake_ancestor))
		state->apply = 0;
	if (state->check_index && is_not_gitdir)
		return error(_("--index outside a repository"));
	if (state->cached) {
		if (is_not_gitdir)
			return error(_("--cached outside a repository"));
		state->check_index = 1;
	}
	if (state->check_index)
		state->unsafe_paths = 0;
	if (!state->lock_file)
		return error("BUG: state->lock_file should not be NULL");

	return 0;
}

static int apply_all_patches(struct apply_state *state,
