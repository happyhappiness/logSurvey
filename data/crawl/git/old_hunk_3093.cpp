
	argc = parse_options(argc, argv, prefix, options, prune_usage, 0);

	if (do_prune_worktrees) {
		if (argc)
			die(_("--worktrees does not take extra arguments"));
		prune_worktrees();
		return 0;
	}

	while (argc--) {
		unsigned char sha1[20];
		const char *name = *argv++;
