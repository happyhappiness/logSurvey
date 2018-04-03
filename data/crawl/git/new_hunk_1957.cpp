	argc = parse_options(argc, argv, state.prefix, builtin_apply_options,
			apply_usage, 0);

	check_apply_state(&state, force_apply);

	for (i = 0; i < argc; i++) {
		const char *arg = argv[i];