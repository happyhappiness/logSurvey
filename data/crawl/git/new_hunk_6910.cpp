	argc = parse_options(argc, argv, options, usage, 0);

	printf("boolean: %d\n", boolean);
	printf("integer: %u\n", integer);
	printf("timestamp: %lu\n", timestamp);
	printf("string: %s\n", string ? string : "(not set)");
	printf("abbrev: %d\n", abbrev);
	printf("verbose: %d\n", verbose);