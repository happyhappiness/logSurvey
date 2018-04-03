	ALLOC_GROW(rev_argv, rev_argv_nr + 1, rev_argv_alloc);
	rev_argv[rev_argv_nr++] = xstrdup("--");

	setup_revisions(rev_argv_nr, rev_argv, &revs, NULL);

	revs.limited = 1;

	if (prepare_revision_walk(&revs))
		die("revision walk setup failed");