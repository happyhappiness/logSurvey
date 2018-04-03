	argc = parse_options(argc, argv, prefix,
			     builtin_fetch_options, builtin_fetch_usage, 0);

	if (unshallow) {
		if (depth)
			die(_("--depth and --unshallow cannot be used together"));
		else if (!is_repository_shallow())
			die(_("--unshallow on a complete repository does not make sense"));
		else {
			static char inf_depth[12];
			sprintf(inf_depth, "%d", INFINITE_DEPTH);
			depth = inf_depth;
		}
	}

	if (recurse_submodules != RECURSE_SUBMODULES_OFF) {
		if (recurse_submodules_default) {
			int arg = parse_fetch_recurse_submodules_arg("--recurse-submodules-default", recurse_submodules_default);
