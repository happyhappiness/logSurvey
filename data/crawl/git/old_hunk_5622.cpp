	argc = parse_options(argc, argv, prefix, builtin_clone_options,
			     builtin_clone_usage, 0);

	if (argc == 0)
		die("You must specify a repository to clone.");

	if (option_mirror)
		option_bare = 1;