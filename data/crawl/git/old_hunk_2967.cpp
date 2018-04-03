		die(_("failed to read the index"));

	if (am_in_progress(&state)) {
		if (resume == RESUME_FALSE)
			resume = RESUME_APPLY;
