	argc = parse_options(argc, argv, builtin_config_options, builtin_config_usage,
			     PARSE_OPT_STOP_AT_NON_OPTION);

	if (use_global_config) {
		char *home = getenv("HOME");
		if (home) {