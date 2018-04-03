		OPT__VERBOSE(&verbose, "be verbose"),
		OPT__DRY_RUN(&dry_run, "dry run"),
		OPT__QUIET(&quiet, "be quiet"),
		OPT_END(),
	};
	int i;

	argc = parse_options(argc, (const char **)argv, prefix, options, usage, 0);

	if (length_cb.called) {
		const char *arg = length_cb.arg;
		int unset = length_cb.unset;
		printf("Callback: \"%s\", %d\n",
		       (arg ? arg : "not set"), unset);
	}
	printf("boolean: %d\n", boolean);
	printf("integer: %d\n", integer);
	printf("magnitude: %lu\n", magnitude);
	printf("timestamp: %lu\n", timestamp);
	printf("string: %s\n", string ? string : "(not set)");
	printf("abbrev: %d\n", abbrev);
	printf("verbose: %d\n", verbose);
	printf("quiet: %d\n", quiet);
	printf("dry run: %s\n", dry_run ? "yes" : "no");
	printf("file: %s\n", file ? file : "(not set)");

	for (i = 0; i < list.nr; i++)
		printf("list: %s\n", list.items[i].string);

	for (i = 0; i < argc; i++)
		printf("arg %02d: %s\n", i, argv[i]);

	return 0;
}