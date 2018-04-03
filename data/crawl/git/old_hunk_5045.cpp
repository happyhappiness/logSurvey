	int rev_nr = 0;
	int show_all = 0;
	int octopus = 0;

	struct option options[] = {
		OPT_BOOLEAN('a', "all", &show_all, "output all common ancestors"),
		OPT_BOOLEAN(0, "octopus", &octopus, "find ancestors for a single n-way merge"),
		OPT_END()
	};

	git_config(git_default_config, NULL);
	argc = parse_options(argc, argv, prefix, options, merge_base_usage, 0);
	if (!octopus && argc < 2)
		usage_with_options(merge_base_usage, options);

	if (octopus)
		return show_octopus_merge_bases(argc, argv, show_all);

	rev = xmalloc(argc * sizeof(*rev));
	while (argc-- > 0)
