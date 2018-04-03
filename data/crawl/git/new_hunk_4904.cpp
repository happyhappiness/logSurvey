	if (entries < 0)
		die("cache corrupted");

	/*
	 * Custom copy of parse_options() because we want to handle
	 * filename arguments as they come.
	 */
	parse_options_start(&ctx, argc, argv, prefix,
			    options, PARSE_OPT_STOP_AT_NON_OPTION);
	while (ctx.argc) {
		if (parseopt_state != PARSE_OPT_DONE)
			parseopt_state = parse_options_step(&ctx, options,
							    update_index_usage);
		if (!ctx.argc)
			break;
		switch (parseopt_state) {
		case PARSE_OPT_HELP:
			exit(129);
		case PARSE_OPT_NON_OPTION:
		case PARSE_OPT_DONE:
		{
			const char *path = ctx.argv[0];
			const char *p;

			setup_work_tree();
			p = prefix_path(prefix, prefix_length, path);
			update_one(p, NULL, 0);
			if (set_executable_bit)
				chmod_path(set_executable_bit, p);
			if (p < path || p > path + strlen(path))
				free((char *)p);
			ctx.argc--;
			ctx.argv++;
			break;
		}
		case PARSE_OPT_UNKNOWN:
			if (ctx.argv[0][1] == '-')
				error("unknown option '%s'", ctx.argv[0] + 2);
			else
				error("unknown switch '%c'", *ctx.opt);
			usage_with_options(update_index_usage, options);
		}
	}
	argc = parse_options_end(&ctx);

	if (read_from_stdin) {
		struct strbuf buf = STRBUF_INIT, nbuf = STRBUF_INIT;

