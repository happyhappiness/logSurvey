		repo = repo_name;
	is_local = path && !is_bundle;
	if (is_local && option_depth)
		warning("--depth is ignored in local clones; use file:// instead.");

	if (argc == 2)
		dir = xstrdup(argv[1]);
