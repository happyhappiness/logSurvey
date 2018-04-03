	struct commit_list **remotes = &remoteheads;

	setup_work_tree();
	if (read_cache_unmerged())
		die("You are in the middle of a conflicted merge.");

	/*
	 * Check if we are _not_ on a detached HEAD, i.e. if there is a
