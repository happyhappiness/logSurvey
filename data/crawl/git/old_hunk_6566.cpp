	argc = parse_options(argc, argv, options, merge_file_usage, 0);
	if (argc != 3)
		usage_with_options(merge_file_usage, options);
	if (quiet)
		freopen("/dev/null", "w", stderr);

	for (i = 0; i < 3; i++) {
		if (!names[i])