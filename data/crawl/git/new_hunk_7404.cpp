		die(wrap_arg_usage);
}

void shortlog_init(struct shortlog *log)
{
	memset(log, 0, sizeof(*log));

	read_mailmap(&log->mailmap, ".mailmap", &log->common_repo_prefix);

	log->list.strdup_paths = 1;
	log->wrap = DEFAULT_WRAPLEN;
	log->in1 = DEFAULT_INDENT1;
	log->in2 = DEFAULT_INDENT2;
}

int cmd_shortlog(int argc, const char **argv, const char *prefix)
{
	struct shortlog log;
	struct rev_info rev;

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
