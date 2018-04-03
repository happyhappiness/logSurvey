			    PARSE_OPT_KEEP_ARGV0);

	for (;;) {
		int n;
		switch (parse_options_step(&ctx, options, shortlog_usage)) {
		case PARSE_OPT_HELP:
			exit(129);
		case PARSE_OPT_DONE:
			goto parse_done;
		}
		n = handle_revision_opt(&rev, ctx.argc, ctx.argv,
					&ctx.cpidx, ctx.out);
		if (n <= 0) {
			error("unknown option `%s'", ctx.argv[0]);
			usage_with_options(shortlog_usage, options);
		}
		ctx.argv += n;
		ctx.argc -= n;
	}
parse_done:
	argc = parse_options_end(&ctx);
