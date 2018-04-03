	const char *best_strategy = NULL, *wt_strategy = NULL;
	struct commit_list **remotes = &remoteheads;

	/*
	 * Check if we are _not_ on a detached HEAD, i.e. if there is a
	 * current branch.
