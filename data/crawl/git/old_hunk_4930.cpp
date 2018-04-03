	int output_fd = -1;
	char *end;

	if (argc < 3)
		die("URL missing");

	input_fd = (int)strtoul(argv[2], &end, 10);

