		else if (!strcmp(argv[1], "--list") || !strcmp(argv[1], "-l")) {
			if (argc != 2)
				usage(git_config_set_usage);
			if (git_config(show_all_config) < 0 && file && errno)
				die("unable to read config file %s: %s", file,
				    strerror(errno));
			return 0;
		}
		else if (!strcmp(argv[1], "--global")) {
			char *home = getenv("HOME");