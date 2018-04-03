		check_argc(argc, 0, 0);
		if (git_config_with_options(show_all_config, NULL,
					    given_config_file,
					    respect_includes) < 0) {
			if (given_config_file)
				die_errno("unable to read config file '%s'",
