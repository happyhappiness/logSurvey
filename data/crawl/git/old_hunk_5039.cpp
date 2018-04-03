		repo = xstrdup(make_absolute_path(repo_name));
	else
		repo = repo_name;

	if (argc == 2)
		dir = xstrdup(argv[1]);
