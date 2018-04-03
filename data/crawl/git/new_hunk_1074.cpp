	const char *tmp;
	int status;

	if (get_super_prefix())
		die("%s doesn't support --super-prefix", argv[0]);

	if (use_pager == -1)
		use_pager = check_pager_config(argv[0]);
	commit_pager_choice();