
int cmd_shortlog(int argc, const char **argv, const char *prefix)
{
	struct shortlog log;
	struct rev_info rev;
	int nongit;

	prefix = setup_git_directory_gently(&nongit);
	shortlog_init(&log);

	/* since -n is a shadowed rev argument, parse our args first */
	while (argc > 1) {
		if (!strcmp(argv[1], "-n") || !strcmp(argv[1], "--numbered"))
			log.sort_by_number = 1;
		else if (!strcmp(argv[1], "-s") ||
				!strcmp(argv[1], "--summary"))
			log.summary = 1;
		else if (!strcmp(argv[1], "-e") ||
			 !strcmp(argv[1], "--email"))
			log.email = 1;
		else if (!prefixcmp(argv[1], "-w")) {
			log.wrap_lines = 1;
			parse_wrap_args(argv[1], &log.in1, &log.in2, &log.wrap);
		}
		else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
			usage(shortlog_usage);
		else
			break;
		argv++;
		argc--;
	}
	init_revisions(&rev, prefix);
	argc = setup_revisions(argc, argv, &rev, NULL);
	if (argc > 1)
		die ("unrecognized argument: %s", argv[1]);

	/* assume HEAD if from a tty */
	if (!nongit && !rev.pending.nr && isatty(0))