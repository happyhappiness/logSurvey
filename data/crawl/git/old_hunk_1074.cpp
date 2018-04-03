	const char *tmp;
	int status;

	if (use_pager == -1)
		use_pager = check_pager_config(argv[0]);
	commit_pager_choice();