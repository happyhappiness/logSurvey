
	config_exclusive_filename = getenv(CONFIG_ENVIRONMENT);

	while (1 < argc) {
		if (!strcmp(argv[1], "--int"))
			type = T_INT;
		else if (!strcmp(argv[1], "--bool"))
			type = T_BOOL;
		else if (!strcmp(argv[1], "--bool-or-int"))
			type = T_BOOL_OR_INT;
		else if (!strcmp(argv[1], "--list") || !strcmp(argv[1], "-l")) {
			if (argc != 2)
				usage(git_config_set_usage);
			if (git_config(show_all_config, NULL) < 0) {
				if (config_exclusive_filename)
					die("unable to read config file %s: %s",
					    config_exclusive_filename, strerror(errno));
				else
					die("error processing config file(s)");
			}
			return 0;
		}
		else if (!strcmp(argv[1], "--global")) {
			char *home = getenv("HOME");
			if (home) {
				char *user_config = xstrdup(mkpath("%s/.gitconfig", home));
				config_exclusive_filename = user_config;
			} else {
				die("$HOME not set");
			}
		}
		else if (!strcmp(argv[1], "--system"))
			config_exclusive_filename = git_etc_gitconfig();
		else if (!strcmp(argv[1], "--file") || !strcmp(argv[1], "-f")) {
			if (argc < 3)
				usage(git_config_set_usage);
			if (!is_absolute_path(argv[2]) && prefix)
				config_exclusive_filename = prefix_filename(prefix,
									    strlen(prefix),
									    argv[2]);
			else
				config_exclusive_filename = argv[2];
			argc--;
			argv++;
		}
		else if (!strcmp(argv[1], "--null") || !strcmp(argv[1], "-z")) {
			term = '\0';
			delim = '\n';
			key_delim = '\n';
		}
		else if (!strcmp(argv[1], "--rename-section")) {
			int ret;
			if (argc != 4)
				usage(git_config_set_usage);
			ret = git_config_rename_section(argv[2], argv[3]);
			if (ret < 0)
				return ret;
			if (ret == 0) {
				fprintf(stderr, "No such section!\n");
				return 1;
			}
			return 0;
		}
		else if (!strcmp(argv[1], "--remove-section")) {
			int ret;
			if (argc != 3)
				usage(git_config_set_usage);
			ret = git_config_rename_section(argv[2], NULL);
			if (ret < 0)
				return ret;
			if (ret == 0) {
				fprintf(stderr, "No such section!\n");
				return 1;
			}
			return 0;
		} else if (!strcmp(argv[1], "--get-color")) {
			if (argc > 4 || argc < 3)
				usage(git_config_set_usage);
			get_color_slot = argv[2];
			get_color(argv[3]);
			return 0;
		} else if (!strcmp(argv[1], "--get-colorbool")) {
			if (argc == 4)
				stdout_is_tty = git_config_bool("command line", argv[3]);
			else if (argc == 3)
				stdout_is_tty = isatty(1);
			else
				usage(git_config_set_usage);
			get_colorbool_slot = argv[2];
			return get_colorbool(argc != 3);
		} else if (!strcmp(argv[1], "--edit") || !strcmp(argv[1], "-e")) {
			if (argc != 2)
				usage(git_config_set_usage);
			git_config(git_default_config, NULL);
			launch_editor(config_exclusive_filename ?
				      config_exclusive_filename : git_path("config"),
				      NULL, NULL);
			return 0;
		} else
			break;
		argc--;
		argv++;
	}

	switch (argc) {
	case 2:
		return get_value(argv[1], NULL);
	case 3:
		if (!strcmp(argv[1], "--unset"))
			return git_config_set(argv[2], NULL);
		else if (!strcmp(argv[1], "--unset-all"))
			return git_config_set_multivar(argv[2], NULL, NULL, 1);
		else if (!strcmp(argv[1], "--get"))
			return get_value(argv[2], NULL);
		else if (!strcmp(argv[1], "--get-all")) {
			do_all = 1;
			return get_value(argv[2], NULL);
		} else if (!strcmp(argv[1], "--get-regexp")) {
			show_keys = 1;
			use_key_regexp = 1;
			do_all = 1;
			return get_value(argv[2], NULL);
		} else {
			value = normalize_value(argv[1], argv[2]);
			return git_config_set(argv[1], value);
		}
	case 4:
		if (!strcmp(argv[1], "--unset"))
			return git_config_set_multivar(argv[2], NULL, argv[3], 0);
		else if (!strcmp(argv[1], "--unset-all"))
			return git_config_set_multivar(argv[2], NULL, argv[3], 1);
		else if (!strcmp(argv[1], "--get"))
			return get_value(argv[2], argv[3]);
		else if (!strcmp(argv[1], "--get-all")) {
			do_all = 1;
			return get_value(argv[2], argv[3]);
		} else if (!strcmp(argv[1], "--get-regexp")) {
			show_keys = 1;
			use_key_regexp = 1;
			do_all = 1;
			return get_value(argv[2], argv[3]);
		} else if (!strcmp(argv[1], "--add")) {
			value = normalize_value(argv[2], argv[3]);
			return git_config_set_multivar(argv[2], value, "^$", 0);
		} else if (!strcmp(argv[1], "--replace-all")) {
			value = normalize_value(argv[2], argv[3]);
			return git_config_set_multivar(argv[2], value, NULL, 1);
		} else {
			value = normalize_value(argv[1], argv[2]);
			return git_config_set_multivar(argv[1], value, argv[3], 0);
		}
	case 5:
		if (!strcmp(argv[1], "--replace-all")) {
			value = normalize_value(argv[2], argv[3]);
			return git_config_set_multivar(argv[2], value, argv[4], 1);
		}
	case 1:
	default:
		usage(git_config_set_usage);
	}
	return 0;
}