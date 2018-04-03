
	argc = parse_options(argc, argv, prefix, options, prune_usage, 0);

	while (argc--) {
		unsigned char sha1[20];
		const char *name = *argv++;
