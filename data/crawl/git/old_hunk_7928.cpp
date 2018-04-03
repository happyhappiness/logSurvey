		else if (!strcmp(argv[1], "--list") || !strcmp(argv[1], "-l")) {
			if (argc != 2)
				usage(git_config_set_usage);
			return git_config(show_all_config);
		}
		else if (!strcmp(argv[1], "--global")) {
			char *home = getenv("HOME");