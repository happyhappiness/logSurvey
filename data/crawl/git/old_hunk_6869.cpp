	struct commit_list **remotes = &remoteheads;

	setup_work_tree();
	if (unmerged_cache())
		die("You are in the middle of a conflicted merge.");

	/*
