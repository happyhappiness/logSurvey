	argc = parse_options(argc, argv, prefix, builtin_merge_options,
			builtin_merge_usage, 0);

	if (read_cache_unmerged())
		die_resolve_conflict("merge");

