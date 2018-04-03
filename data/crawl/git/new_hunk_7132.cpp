		diff_use_color_default = git_use_color_default;

	init_revisions(&rev, prefix);

	/* If this is a no-index diff, just run it and exit there. */
	diff_no_index(&rev, argc, argv, nongit, prefix);

	/* Otherwise, we are doing the usual "git" diff */
	rev.diffopt.skip_stat_unmatch = !!diff_auto_refresh_index;

	if (nongit)
		die("Not a git repository");
	argc = setup_revisions(argc, argv, &rev, NULL);
	if (!rev.diffopt.output_format) {
		rev.diffopt.output_format = DIFF_FORMAT_PATCH;
		if (diff_setup_done(&rev.diffopt) < 0)
			die("diff_setup_done failed");
	}
	DIFF_OPT_SET(&rev.diffopt, ALLOW_EXTERNAL);
	DIFF_OPT_SET(&rev.diffopt, RECURSIVE);

