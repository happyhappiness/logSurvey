	if (!argc)
		return 0;

	if (!strcmp(argv[0], "--"))	/* case (2) */
		return 1;

	arg = argv[0];
	has_dash_dash = (argc > 1) && !strcmp(argv[1], "--");

	if (!strcmp(arg, "-"))
		arg = "@{-1}";
