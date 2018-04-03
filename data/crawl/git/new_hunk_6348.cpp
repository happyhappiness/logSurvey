		die ("-n and -k are mutually exclusive.");
	if (keep_subject && subject_prefix)
		die ("--subject-prefix and -k are mutually exclusive.");

	argc = setup_revisions(argc, argv, &rev, "HEAD");
	if (argc > 1)