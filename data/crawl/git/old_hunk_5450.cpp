		rename_branch(head, argv[0], rename > 1);
	else if (rename && (argc == 2))
		rename_branch(argv[0], argv[1], rename > 1);
	else if (argc <= 2)
		create_branch(head, argv[0], (argc == 2) ? argv[1] : head,
			      force_create, reflog, track);
	else
		usage_with_options(builtin_branch_usage, options);

	return 0;
