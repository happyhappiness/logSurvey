	init_revisions(&revs, prefix);

	argc = parse_options(argc, argv, options, prune_usage, 0);
	if (argc)
		die ("unrecognized argument: %s", name);
	mark_reachable_objects(&revs, 1);
	prune_object_dir(get_object_directory());

