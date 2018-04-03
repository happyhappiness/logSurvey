	if (isatty(0))
		opts.edit = 1;
	opts.action = REPLAY_REVERT;
	git_config(common_config, NULL);
	res = run_sequencer(argc, argv, &opts);
	if (res < 0)
		die(_("revert failed"));
