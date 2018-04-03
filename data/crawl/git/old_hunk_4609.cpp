	get_patch_ids(&revs, &ids, prefix);

	if (limit && add_pending_commit(limit, &revs, UNINTERESTING))
		die("Unknown commit %s", limit);

	/* reverse the list of commits */
	if (prepare_revision_walk(&revs))
		die("revision walk setup failed");
	while ((commit = get_revision(&revs)) != NULL) {
		/* ignore merges */
		if (commit->parents && commit->parents->next)