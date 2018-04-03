	}
	discard_cache();

	if (!commit->parents) {
		if (action == REVERT)
			die ("Cannot revert a root commit");
