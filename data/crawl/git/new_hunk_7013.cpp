
int cmd_shortlog(int argc, const char **argv, const char *prefix)
{
	static struct shortlog log;
	static struct rev_info rev;
	int nongit;

	static const struct option options[] = {
		OPT_BOOLEAN('n', "numbered", &log.sort_by_number,
			    "sort output according to the number of commits per author"),
		OPT_BOOLEAN('s', "summary", &log.summary,
			    "Suppress commit descriptions, only provides commit count"),
		OPT_BOOLEAN('e', "email", &log.email,
			    "Show the email address of each author"),
		{ OPTION_CALLBACK, 'w', NULL, &log, "w[,i1[,i2]]",
			"Linewrap output", PARSE_OPT_OPTARG, &parse_wrap_args },
		OPT_END(),
	};

	struct parse_opt_ctx_t ctx;

	prefix = setup_git_directory_gently(&nongit);
	shortlog_init(&log);
	init_revisions(&rev, prefix);
	parse_options_start(&ctx, argc, argv, PARSE_OPT_KEEP_DASHDASH |
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

	if (setup_revisions(argc, argv, &rev, NULL) != 1) {
		error("unrecognized argument: %s", argv[1]);
		usage_with_options(shortlog_usage, options);
	}

	/* assume HEAD if from a tty */
	if (!nongit && !rev.pending.nr && isatty(0))