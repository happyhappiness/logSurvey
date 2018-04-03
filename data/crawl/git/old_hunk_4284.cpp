	discard_cache();

	if (!commit->parents) {
		if (action == REVERT)
			die (_("Cannot revert a root commit"));
		parent = NULL;
	}
	else if (commit->parents->next) {
