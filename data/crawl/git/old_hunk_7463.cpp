		die("Unknown commit %s", limit);

	/* reverse the list of commits */
	prepare_revision_walk(&revs);
	while ((commit = get_revision(&revs)) != NULL) {
		/* ignore merges */
		if (commit->parents && commit->parents->next)
