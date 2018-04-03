{
	struct child_process c;
	int force = 0, detach = 0;
	const char *path, *branch;
	struct argv_array cmd = ARGV_ARRAY_INIT;
	struct option options[] = {
		OPT__FORCE(&force, N_("checkout <branch> even if already checked out in other worktree")),
		OPT_BOOL(0, "detach", &detach, N_("detach HEAD at named commit")),
		OPT_END()
	};

	ac = parse_options(ac, av, prefix, options, worktree_usage, 0);
	if (ac != 2)
		usage_with_options(worktree_usage, options);

