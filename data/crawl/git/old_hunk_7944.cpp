	char *prog;
	struct commands *cmd;

	/* We want to see "-c cmd args", and nothing else */
	if (argc != 3 || strcmp(argv[1], "-c"))
		die("What do you think I am? A shell?");

	prog = argv[2];