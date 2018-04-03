
	newfd = hold_locked_index(&lock_file, 1);

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

		if (get_sha1(arg, sha1))
			die("Not a valid object name %s", arg);
		if (list_tree(sha1) < 0)
			die("failed to unpack tree object %s", arg);
		stage++;
	}
	if (1 < opts.index_only + opts.update)
		die("-u and -i at the same time makes no sense");
	if ((opts.update||opts.index_only) && !opts.merge)
		die("%s is meaningless without -m, --reset, or --prefix",
		    opts.update ? "-u" : "-i");
