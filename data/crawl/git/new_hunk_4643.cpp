	DIFF_OPT_SET(&rev.diffopt, ALLOW_TEXTCONV);

	if (nongit)
		die(_("Not a git repository"));
	argc = setup_revisions(argc, argv, &rev, NULL);
	if (!rev.diffopt.output_format) {
		rev.diffopt.output_format = DIFF_FORMAT_PATCH;
		if (diff_setup_done(&rev.diffopt) < 0)
			die(_("diff_setup_done failed"));
	}

	DIFF_OPT_SET(&rev.diffopt, RECURSIVE);
