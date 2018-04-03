
int cmd_fmt_merge_msg(int argc, const char **argv, const char *prefix)
{
	FILE *in = stdin;
	struct strbuf input, output;
	int ret;

	git_config(fmt_merge_msg_config, NULL);

	while (argc > 1) {
		if (!strcmp(argv[1], "--log") || !strcmp(argv[1], "--summary"))
			merge_summary = 1;
		else if (!strcmp(argv[1], "--no-log")
				|| !strcmp(argv[1], "--no-summary"))
			merge_summary = 0;
		else if (!strcmp(argv[1], "-F") || !strcmp(argv[1], "--file")) {
			if (argc < 3)
				die ("Which file?");
			if (!strcmp(argv[2], "-"))
				in = stdin;
			else {
				fclose(in);
				in = fopen(argv[2], "r");
				if (!in)
					die("cannot open %s", argv[2]);
			}
			argc--; argv++;
		} else
			break;
		argc--; argv++;
	}

	if (argc > 1)
		usage(fmt_merge_msg_usage);

	strbuf_init(&input, 0);
	if (strbuf_read(&input, fileno(in), 0) < 0)
		die("could not read input file %s", strerror(errno));
