	argc = parse_options(argc, argv, prefix, builtin_clone_options,
			     builtin_clone_usage, 0);

	if (argc > 2)
		usage_msg_opt("Too many arguments.",
			builtin_clone_usage, builtin_clone_options);

	if (argc == 0)
		usage_msg_opt("You must specify a repository to clone.",
			builtin_clone_usage, builtin_clone_options);

	if (option_mirror)
		option_bare = 1;