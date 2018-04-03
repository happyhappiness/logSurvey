
	memset(&opts, 0, sizeof(opts));
	ac = parse_options(ac, av, prefix, options, worktree_usage, 0);
	if (opts.new_branch && new_branch_force)
		die(_("-b and -B are mutually exclusive"));
	if (ac < 1 || ac > 2)
		usage_with_options(worktree_usage, options);

