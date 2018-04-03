
	argc = parse_options(argc, argv, prefix, options, usage, 0);

	if (am_in_progress(&state))
		am_load(&state);
	else {