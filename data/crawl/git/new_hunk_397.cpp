	char *end;

	if (argc != 3)
		usage(usage_msg);

	input_fd = (int)strtoul(argv[2], &end, 10);
