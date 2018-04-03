	struct strbuf buf = STRBUF_INIT;
	const char *url;
	struct walker *walker = NULL;

	git_extract_argv0_path(argv[0]);
	setup_git_directory();
	if (argc < 2) {
		fprintf(stderr, "Remote needed\n");
		return 1;
