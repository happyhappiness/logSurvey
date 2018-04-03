	if (!use_stdout)
		realstdout = xfdopen(xdup(1), "w");

	if (prepare_revision_walk(&rev))
		die("revision walk setup failed");
	while ((commit = get_revision(&rev)) != NULL) {
		/* ignore merges */
		if (commit->parents && commit->parents->next)
