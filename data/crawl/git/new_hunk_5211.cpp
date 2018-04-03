	setenv(GIT_REFLOG_ACTION, me, 0);
	parse_args(argc, argv);

	if (allow_ff) {
		if (signoff)
			die("cherry-pick --ff cannot be used with --signoff");
