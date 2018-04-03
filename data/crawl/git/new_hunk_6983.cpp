
	git_config(git_default_config, NULL);

	argc = parse_options(argc, argv, builtin_rm_options, builtin_rm_usage, 0);
	if (!argc)
		usage_with_options(builtin_rm_usage, builtin_rm_options);

	if (!index_only)
		setup_work_tree();

	newfd = hold_locked_index(&lock_file, 1);

	if (read_cache() < 0)
		die("index file corrupt");

	pathspec = get_pathspec(prefix, argv);
	seen = NULL;
	for (i = 0; pathspec[i] ; i++)
