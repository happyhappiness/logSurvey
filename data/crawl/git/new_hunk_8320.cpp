		die ("-n and -k are mutually exclusive.");
	if (keep_subject && subject_prefix)
		die ("--subject-prefix and -k are mutually exclusive.");
	if (numbered_files && use_stdout)
		die ("--numbered-files and --stdout are mutually exclusive.");

	argc = setup_revisions(argc, argv, &rev, "HEAD");
	if (argc > 1)
