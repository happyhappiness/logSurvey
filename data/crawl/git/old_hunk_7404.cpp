		die(wrap_arg_usage);
}

int cmd_shortlog(int argc, const char **argv, const char *prefix)
{
	struct rev_info rev;
	struct path_list list = { NULL, 0, 0, 1 };
	int i, j, sort_by_number = 0, summary = 0;
	int wrap_lines = 0;
	int wrap = DEFAULT_WRAPLEN;
	int in1 = DEFAULT_INDENT1;
	int in2 = DEFAULT_INDENT2;

	/* since -n is a shadowed rev argument, parse our args first */
	while (argc > 1) {
		if (!strcmp(argv[1], "-n") || !strcmp(argv[1], "--numbered"))
			sort_by_number = 1;
		else if (!strcmp(argv[1], "-s") ||
				!strcmp(argv[1], "--summary"))
			summary = 1;
		else if (!strcmp(argv[1], "-e") ||
			 !strcmp(argv[1], "--email"))
			email = 1;
		else if (!prefixcmp(argv[1], "-w")) {
			wrap_lines = 1;
			parse_wrap_args(argv[1], &in1, &in2, &wrap);
		}
		else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
			usage(shortlog_usage);
