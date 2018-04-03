	argc = parse_options(argc, argv, prefix, module_list_options,
			     git_submodule_helper_usage, 0);

	if (module_list_compute(argc, argv, prefix, &pathspec, &list) < 0) {
		printf("#unmatched\n");
		return 1;
	}

	for (i = 0; i < list.nr; i++) {
		const struct cache_entry *ce = list.entries[i];
