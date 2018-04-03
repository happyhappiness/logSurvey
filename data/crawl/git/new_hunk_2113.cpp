	struct commit **rev;
	int i = 0, rev_nr = 0;

	if (base_commit && strcmp(base_commit, "auto")) {
		base = lookup_commit_reference_by_name(base_commit);
		if (!base)
			die(_("Unknown commit %s"), base_commit);
	} else if ((base_commit && !strcmp(base_commit, "auto")) || base_auto) {
		struct branch *curr_branch = branch_get(NULL);
		const char *upstream = branch_get_upstream(curr_branch, NULL);
		if (upstream) {
