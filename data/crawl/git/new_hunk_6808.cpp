	int cnt = 0;
	struct rev_info rev;

	/* Check how many files differ. */
	init_revisions(&rev, "");
	setup_revisions(0, NULL, &rev, NULL);
