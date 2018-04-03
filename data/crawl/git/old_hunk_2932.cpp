
	argc = parse_options(argc, argv, prefix, options, usage, 0);

	if (read_index_preload(&the_index, NULL) < 0)
		die(_("failed to read the index"));
