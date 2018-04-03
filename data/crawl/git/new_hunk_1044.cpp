	int is_not_gitdir = !startup_info->have_repository;

	if (state->apply_with_reject && state->threeway)
		return error(_("--reject and --3way cannot be used together."));
	if (state->cached && state->threeway)
		return error(_("--cached and --3way cannot be used together."));
	if (state->threeway) {
		if (is_not_gitdir)
			return error(_("--3way outside a repository"));
