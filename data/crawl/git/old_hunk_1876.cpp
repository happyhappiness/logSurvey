	argc = parse_options(argc, argv, prefix,
			     builtin_fetch_options, builtin_fetch_usage, 0);

	if (unshallow) {
		if (depth)
			die(_("--depth and --unshallow cannot be used together"));
