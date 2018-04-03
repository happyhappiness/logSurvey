	/* &state->fn_table is cleared at the end of apply_patch() */
}

static void check_apply_state(struct apply_state *state, int force_apply)
{
	int is_not_gitdir = !startup_info->have_repository;

	if (state->apply_with_reject && state->threeway)
		die("--reject and --3way cannot be used together.");
	if (state->cached && state->threeway)
		die("--cached and --3way cannot be used together.");
	if (state->threeway) {
		if (is_not_gitdir)
			die(_("--3way outside a repository"));
		state->check_index = 1;
	}
	if (state->apply_with_reject)
		state->apply = state->apply_verbosely = 1;
	if (!force_apply && (state->diffstat || state->numstat || state->summary || state->check || state->fake_ancestor))
		state->apply = 0;
	if (state->check_index && is_not_gitdir)
		die(_("--index outside a repository"));
	if (state->cached) {
		if (is_not_gitdir)
			die(_("--cached outside a repository"));
		state->check_index = 1;
	}
	if (state->check_index)
		state->unsafe_paths = 0;
}

int cmd_apply(int argc, const char **argv, const char *prefix)
{
	int i;
	int errs = 0;
	int force_apply = 0;
	int options = 0;
	int read_stdin = 1;
