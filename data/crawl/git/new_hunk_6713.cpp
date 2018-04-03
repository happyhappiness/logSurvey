
int cmd_fmt_merge_msg(int argc, const char **argv, const char *prefix)
{
	const char *inpath = NULL;
	struct option options[] = {
		OPT_BOOLEAN(0, "log",     &merge_summary, "populate log with the shortlog"),
		OPT_BOOLEAN(0, "summary", &merge_summary, "alias for --log"),
		OPT_STRING('F', "file",   &inpath, "file", "file to read from"),
		OPT_END()
	};

	FILE *in = stdin;
	struct strbuf input, output;
	int ret;

	git_config(fmt_merge_msg_config, NULL);
	argc = parse_options(argc, argv, options, fmt_merge_msg_usage, 0);
	if (argc > 0)
		usage_with_options(fmt_merge_msg_usage, options);

	if (inpath && strcmp(inpath, "-")) {
		in = fopen(inpath, "r");
		if (!in)
			die("cannot open %s", inpath);
	}

	strbuf_init(&input, 0);
	if (strbuf_read(&input, fileno(in), 0) < 0)
		die("could not read input file %s", strerror(errno));
