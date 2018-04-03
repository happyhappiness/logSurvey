	argc = parse_options(argc, argv, options, merge_file_usage, 0);
	if (argc != 3)
		usage_with_options(merge_file_usage, options);
	if (quiet) {
		if (!freopen("/dev/null", "w", stderr))
			return error("failed to redirect stderr to /dev/null: "
				     "%s\n", strerror(errno));
	}

	for (i = 0; i < 3; i++) {
		if (!names[i])