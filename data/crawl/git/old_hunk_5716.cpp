	argc = parse_options(argc, argv, unused_prefix, read_tree_options,
			     read_tree_usage, 0);

	if (read_cache_unmerged() && (opts.prefix || opts.merge))
		die("You need to resolve your current index first");

	prefix_set = opts.prefix ? 1 : 0;
	if (1 < opts.merge + opts.reset + prefix_set)
		die("Which one? -m, --reset, or --prefix?");
	stage = opts.merge = (opts.reset || opts.merge || prefix_set);

	for (i = 0; i < argc; i++) {
		const char *arg = argv[i];
