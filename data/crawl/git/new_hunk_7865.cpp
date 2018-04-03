{
	int quiet = 0;
	const char *msg = NULL;
	struct option options[] = {
		OPT__QUIET(&quiet),
		OPT_STRING('m', NULL, &msg, "reason", "reason of the update"),
		OPT_END(),
	};

	git_config(git_default_config);
	argc = parse_options(argc, argv, options, git_symbolic_ref_usage, 0);
	if (msg &&!*msg)
		die("Refusing to perform update with empty message");
	switch (argc) {
	case 1:
		check_symref(argv[0], quiet);
		break;
	case 2:
		create_symref(argv[0], argv[1], msg);
		break;
	default:
		usage_with_options(git_symbolic_ref_usage, options);
	}
	return 0;
}