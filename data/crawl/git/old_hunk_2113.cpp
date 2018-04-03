	struct commit **rev;
	int i = 0, rev_nr = 0;

	if (!strcmp(base_commit, "auto")) {
		struct branch *curr_branch = branch_get(NULL);
		const char *upstream = branch_get_upstream(curr_branch, NULL);
		if (upstream) {
