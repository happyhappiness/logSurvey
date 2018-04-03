{
	int quiet = 0;
	const char *msg = NULL;

	git_config(git_default_config);

	while (1 < argc) {
		const char *arg = argv[1];
		if (arg[0] != '-')
			break;
		else if (!strcmp("-q", arg))
			quiet = 1;
		else if (!strcmp("-m", arg)) {
			argc--;
			argv++;
			if (argc <= 1)
				break;
			msg = argv[1];
			if (!*msg)
				die("Refusing to perform update with empty message");
		}
		else if (!strcmp("--", arg)) {
			argc--;
			argv++;
			break;
		}
		else
			die("unknown option %s", arg);
		argc--;
		argv++;
	}

	switch (argc) {
	case 2:
		check_symref(argv[1], quiet);
		break;
	case 3:
		create_symref(argv[1], argv[2], msg);
		break;
	default:
		usage(git_symbolic_ref_usage);
	}
	return 0;
}