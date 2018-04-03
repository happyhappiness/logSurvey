	argc = parse_options(argc, argv, prefix, options, checkout_usage,
			     PARSE_OPT_KEEP_DASHDASH);

	/* --track without -b should DWIM */
	if (0 < opts.track && !opts.new_branch) {
		const char *argv0 = argv[0];
