
	argc = parse_options(argc, argv, options, builtin_remote_usage, 0);

	if (argc < 1)
		return show_all();

	memset(&states, 0, sizeof(states));
	for (; argc; argc--, argv++) {
		struct strbuf buf;
		int i;

		get_remote_ref_states(*argv, &states, !no_query);

		printf("* remote %s\n  URL: %s\n", *argv,
			states.remote->url_nr > 0 ?
