	argc = parse_options(argc, argv, prefix, builtin_merge_options,
			builtin_merge_usage, 0);

	if (abort_current_merge) {
		int nargc = 2;
		const char *nargv[] = {"reset", "--merge", NULL};

		if (!file_exists(git_path("MERGE_HEAD")))
			die("There is no merge to abort (MERGE_HEAD missing).");

		/* Invoke 'git reset --merge' */
		return cmd_reset(nargc, nargv, prefix);
	}

	if (read_cache_unmerged())
		die_resolve_conflict("merge");

