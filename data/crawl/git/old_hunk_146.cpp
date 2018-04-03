	int res;

	opts.action = REPLAY_PICK;
	git_config(common_config, NULL);
	res = run_sequencer(argc, argv, &opts);
	if (res < 0)
		die(_("cherry-pick failed"));
