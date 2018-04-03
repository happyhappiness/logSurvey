	if (argc > 1 && !strcmp("--sq-quote", argv[1]))
		return cmd_sq_quote(argc - 2, argv + 2);

	if (argc == 2 && !strcmp("--local-env-vars", argv[1])) {
		int i;
		for (i = 0; local_repo_env[i]; i++)
			printf("%s\n", local_repo_env[i]);
		return 0;
	}

	if (argc > 1 && !strcmp("-h", argv[1]))
		usage(builtin_rev_parse_usage);
