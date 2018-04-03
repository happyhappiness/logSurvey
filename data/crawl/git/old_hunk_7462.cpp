	if (!use_stdout)
		realstdout = xfdopen(xdup(1), "w");

	prepare_revision_walk(&rev);
	while ((commit = get_revision(&rev)) != NULL) {
		/* ignore merges */
		if (commit->parents && commit->parents->next)
