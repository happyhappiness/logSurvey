	return final_commit_name;
}

static int blame_copy_callback(const struct option *option, const char *arg, int unset)
{
	int *opt = option->value;

	/*
	 * -C enables copy from removed files;
	 * -C -C enables copy from existing files, but only
	 *       when blaming a new file;
	 * -C -C -C enables copy from existing files for
	 *          everybody
	 */
	if (*opt & PICKAXE_BLAME_COPY_HARDER)
		*opt |= PICKAXE_BLAME_COPY_HARDEST;
	if (*opt & PICKAXE_BLAME_COPY)
		*opt |= PICKAXE_BLAME_COPY_HARDER;
	*opt |= PICKAXE_BLAME_COPY | PICKAXE_BLAME_MOVE;

	if (arg)
		blame_copy_score = parse_score(arg);
	return 0;
}

static int blame_move_callback(const struct option *option, const char *arg, int unset)
{
	int *opt = option->value;

	*opt |= PICKAXE_BLAME_MOVE;

	if (arg)
		blame_move_score = parse_score(arg);
	return 0;
}

static int blame_bottomtop_callback(const struct option *option, const char *arg, int unset)
{
	const char **bottomtop = option->value;
	if (!arg)
		return -1;
	if (*bottomtop)
		die("More than one '-L n,m' option given");
	*bottomtop = arg;
	return 0;
}

int cmd_blame(int argc, const char **argv, const char *prefix)
{
	struct rev_info revs;
	const char *path;
	struct scoreboard sb;
	struct origin *o;
	struct blame_entry *ent;
	int i, seen_dashdash, unk;
	long bottom, top, lno;
	const char *final_commit_name = NULL;
	enum object_type type;

	static const char *bottomtop = NULL;
	static int output_option = 0, opt = 0;
	static int show_stats = 0;
	static const char *revs_file = NULL;
	static const char *contents_from = NULL;
	static const struct option options[] = {
		OPT_BOOLEAN(0, "incremental", &incremental, "Show blame entries as we find them, incrementally"),
		OPT_BOOLEAN('b', NULL, &blank_boundary, "Show blank SHA-1 for boundary commits (Default: off)"),
		OPT_BOOLEAN(0, "root", &show_root, "Do not treat root commits as boundaries (Default: off)"),
		OPT_BOOLEAN(0, "show-stats", &show_stats, "Show work cost statistics"),
		OPT_BIT(0, "score-debug", &output_option, "Show output score for blame entries", OUTPUT_SHOW_SCORE),
		OPT_BIT('f', "show-name", &output_option, "Show original filename (Default: auto)", OUTPUT_SHOW_NAME),
		OPT_BIT('n', "show-number", &output_option, "Show original linenumber (Default: off)", OUTPUT_SHOW_NUMBER),
		OPT_BIT('p', "porcelain", &output_option, "Show in a format designed for machine consumption", OUTPUT_PORCELAIN),
		OPT_BIT('c', NULL, &output_option, "Use the same output mode as git-annotate (Default: off)", OUTPUT_ANNOTATE_COMPAT),
		OPT_BIT('t', NULL, &output_option, "Show raw timestamp (Default: off)", OUTPUT_RAW_TIMESTAMP),
		OPT_BIT('l', NULL, &output_option, "Show long commit SHA1 (Default: off)", OUTPUT_LONG_OBJECT_NAME),
		OPT_BIT('s', NULL, &output_option, "Suppress author name and timestamp (Default: off)", OUTPUT_NO_AUTHOR),
		OPT_BIT('w', NULL, &xdl_opts, "Ignore whitespace differences", XDF_IGNORE_WHITESPACE),
		OPT_STRING('S', NULL, &revs_file, "file", "Use revisions from <file> instead of calling git-rev-list"),
		OPT_STRING(0, "contents", &contents_from, "file", "Use <file>'s contents as the final image"),
		{ OPTION_CALLBACK, 'C', NULL, &opt, "score", "Find line copies within and across files", PARSE_OPT_OPTARG, blame_copy_callback },
		{ OPTION_CALLBACK, 'M', NULL, &opt, "score", "Find line movements within and across files", PARSE_OPT_OPTARG, blame_move_callback },
		OPT_CALLBACK('L', NULL, &bottomtop, "n,m", "Process only line range n,m, counting from 1", blame_bottomtop_callback),
		OPT_END()
	};

	struct parse_opt_ctx_t ctx;

	cmd_is_annotate = !strcmp(argv[0], "annotate");

	git_config(git_blame_config, NULL);
	init_revisions(&revs, NULL);
	save_commit_buffer = 0;

	parse_options_start(&ctx, argc, argv, PARSE_OPT_KEEP_DASHDASH |
			    PARSE_OPT_KEEP_ARGV0);
	for (;;) {
		int n;

		switch (parse_options_step(&ctx, options, blame_opt_usage)) {
		case PARSE_OPT_HELP:
			exit(129);
		case PARSE_OPT_DONE:
			goto parse_done;
		}

		if (!strcmp(ctx.argv[0], "--reverse")) {
			ctx.argv[0] = "--children";
			reverse = 1;
		}
		n = handle_revision_opt(&revs, ctx.argc, ctx.argv,
					&ctx.cpidx, ctx.out);
		if (n <= 0) {
			error("unknown option `%s'", ctx.argv[0]);
			usage_with_options(blame_opt_usage, options);
		}
		ctx.argv += n;
		ctx.argc -= n;
	}
parse_done:
	argc = parse_options_end(&ctx);

	seen_dashdash = 0;
	for (unk = i = 1; i < argc; i++) {
		const char *arg = argv[i];
		if (*arg != '-')
			break;
		else if (!strcmp("--", arg)) {
			seen_dashdash = 1;
			i++;
