	argc = parse_options(argc, argv, options, usage, 0);

	printf("boolean: %d\n", boolean);
	printf("integer: %lu\n", integer);
	printf("string: %s\n", string ? string : "(not set)");
	printf("abbrev: %d\n", abbrev);
	printf("verbose: %d\n", verbose);