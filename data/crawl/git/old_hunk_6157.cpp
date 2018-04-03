	return 0;
}

static int get_colorbool(int argc, const char **argv)
{
	/*
	 * git config --get-colorbool <slot> [<stdout-is-tty>]
	 *
	 * returns "true" or "false" depending on how <slot>
	 * is configured.
	 */

	if (argc == 2)
		stdout_is_tty = git_config_bool("command line", argv[1]);
	else if (argc == 1)
		stdout_is_tty = isatty(1);
	else
		usage(git_config_set_usage);
	get_colorbool_found = -1;
	get_diff_color_found = -1;
	get_color_slot = argv[0];
	git_config(git_get_colorbool_config, NULL);

	if (get_colorbool_found < 0) {
		if (!strcmp(get_color_slot, "color.diff"))
			get_colorbool_found = get_diff_color_found;
		if (get_colorbool_found < 0)
			get_colorbool_found = git_use_color_default;
	}

	if (argc == 1) {
		return get_colorbool_found ? 0 : 1;
	} else {
		printf("%s\n", get_colorbool_found ? "true" : "false");
		return 0;
	}
}

int cmd_config(int argc, const char **argv, const char *prefix)
{
	int nongit;
	char* value;
	const char *file = setup_git_directory_gently(&nongit);

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
			if (git_config(show_all_config, NULL) < 0 &&
					file && errno)
				die("unable to read config file %s: %s", file,
				    strerror(errno));
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
			if (!is_absolute_path(argv[2]) && file)
				file = prefix_filename(file, strlen(file),
						       argv[2]);
			else
				file = argv[2];
			config_exclusive_filename = file;
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
			return get_color(argc-2, argv+2);
		} else if (!strcmp(argv[1], "--get-colorbool")) {
			return get_colorbool(argc-2, argv+2);
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
