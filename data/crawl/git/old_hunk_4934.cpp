
	argc = parse_options(argc, argv, prefix, builtin_merge_options,
			builtin_merge_usage, 0);
	if (verbosity < 0)
		show_diffstat = 0;
