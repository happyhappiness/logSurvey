	const char *git_dir;
	const char *template_dir = NULL;
	unsigned int flags = 0;
	int i;

	for (i = 1; i < argc; i++, argv++) {
		const char *arg = argv[1];
		if (!prefixcmp(arg, "--template="))
			template_dir = arg+11;
		else if (!strcmp(arg, "--bare")) {
			static char git_dir[PATH_MAX+1];
			is_bare_repository_cfg = 1;
			setenv(GIT_DIR_ENVIRONMENT, getcwd(git_dir,
						sizeof(git_dir)), 0);
		} else if (!strcmp(arg, "--shared"))
			init_shared_repository = PERM_GROUP;
		else if (!prefixcmp(arg, "--shared="))
			init_shared_repository = git_config_perm("arg", arg+9);
		else if (!strcmp(arg, "-q") || !strcmp(arg, "--quiet"))
			flags |= INIT_DB_QUIET;
		else
			usage(init_db_usage);
	}

	if (init_shared_repository != -1)
		shared_repository = init_shared_repository;

