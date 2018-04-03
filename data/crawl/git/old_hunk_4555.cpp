
	setup_revisions(0, NULL, &rev, NULL);
	if (prepare_revision_walk(&rev))
		die("revision walk setup failed");

	ctx.abbrev = rev.abbrev;
	ctx.date_mode = rev.date_mode;
