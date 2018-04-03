
	config_exclusive_filename = getenv(CONFIG_ENVIRONMENT);

	argc = parse_options(argc, argv, builtin_config_options, builtin_config_usage,
			     PARSE_OPT_STOP_AT_NON_OPTION);

	if (use_global_config) {
		char *home = getenv("HOME");
		if (home) {
			char *user_config = xstrdup(mkpath("%s/.gitconfig", home));
			config_exclusive_filename = user_config;
		} else {
			die("$HOME not set");
		}
	}
	else if (use_system_config)
		config_exclusive_filename = git_etc_gitconfig();
	else if (given_config_file) {
		if (!is_absolute_path(given_config_file) && prefix)
			config_exclusive_filename = prefix_filename(prefix,
								    strlen(prefix),
								    argv[2]);
		else
			config_exclusive_filename = given_config_file;
	}

	if (end_null) {
		term = '\0';
		delim = '\n';
		key_delim = '\n';
	}

	if (get_color_slot)
	    actions |= ACTION_GET_COLOR;
	if (get_colorbool_slot)
	    actions |= ACTION_GET_COLORBOOL;

	if (HAS_MULTI_BITS(actions)) {
		error("only one action at a time.");
		usage_with_options(builtin_config_usage, builtin_config_options);
	}
	if (actions == 0)
		switch (argc) {
		case 1: actions = ACTION_GET; break;
		case 2: actions = ACTION_SET; break;
		case 3: actions = ACTION_SET_ALL; break;
		default:
			usage_with_options(builtin_config_usage, builtin_config_options);
		}

	if (actions == ACTION_LIST) {
		if (git_config(show_all_config, NULL) < 0) {
			if (config_exclusive_filename)
				die("unable to read config file %s: %s",
				    config_exclusive_filename, strerror(errno));
			else
				die("error processing config file(s)");
		}
	}
	else if (actions == ACTION_EDIT) {
		git_config(git_default_config, NULL);
		launch_editor(config_exclusive_filename ?
			      config_exclusive_filename : git_path("config"),
			      NULL, NULL);
	}
	else if (actions == ACTION_SET) {
		check_argc(argc, 2, 2);
		value = normalize_value(argv[0], argv[1]);
		return git_config_set(argv[0], value);
	}
	else if (actions == ACTION_SET_ALL) {
		check_argc(argc, 2, 3);
		value = normalize_value(argv[0], argv[1]);
		return git_config_set_multivar(argv[0], value, argv[2], 0);
	}
	else if (actions == ACTION_ADD) {
		check_argc(argc, 2, 2);
		value = normalize_value(argv[0], argv[1]);
		return git_config_set_multivar(argv[0], value, "^$", 0);
	}
	else if (actions == ACTION_REPLACE_ALL) {
		check_argc(argc, 2, 3);
		value = normalize_value(argv[0], argv[1]);
		return git_config_set_multivar(argv[0], value, argv[2], 1);
	}
	else if (actions == ACTION_GET) {
		check_argc(argc, 1, 2);
		return get_value(argv[0], argv[1]);
	}
	else if (actions == ACTION_GET_ALL) {
		do_all = 1;
		check_argc(argc, 1, 2);
		return get_value(argv[0], argv[1]);
	}
	else if (actions == ACTION_GET_REGEXP) {
		show_keys = 1;
		use_key_regexp = 1;
		do_all = 1;
		check_argc(argc, 1, 2);
		return get_value(argv[0], argv[1]);
	}
	else if (actions == ACTION_UNSET) {
		check_argc(argc, 1, 2);
		if (argc == 2)
			return git_config_set_multivar(argv[0], NULL, argv[1], 0);
		else
			return git_config_set(argv[0], NULL);
	}
	else if (actions == ACTION_UNSET_ALL) {
		check_argc(argc, 1, 2);
		return git_config_set_multivar(argv[0], NULL, argv[1], 1);
	}
	else if (actions == ACTION_RENAME_SECTION) {
		int ret;
		check_argc(argc, 2, 2);
		ret = git_config_rename_section(argv[0], argv[1]);
		if (ret < 0)
			return ret;
		if (ret == 0)
			die("No such section!");
	}
	else if (actions == ACTION_REMOVE_SECTION) {
		int ret;
		check_argc(argc, 1, 1);
		ret = git_config_rename_section(argv[0], NULL);
		if (ret < 0)
			return ret;
		if (ret == 0)
			die("No such section!");
	}
	else if (actions == ACTION_GET_COLOR) {
		get_color(argv[0]);
	}
	else if (actions == ACTION_GET_COLORBOOL) {
		if (argc == 1)
			stdout_is_tty = git_config_bool("command line", argv[0]);
		else if (argc == 0)
			stdout_is_tty = isatty(1);
		return get_colorbool(argc != 0);
	}

	return 0;
}