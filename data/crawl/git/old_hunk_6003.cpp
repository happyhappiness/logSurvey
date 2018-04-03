	argc = parse_options(argc, argv, prefix, options, git_replace_usage, 0);

	if (list && delete)
		usage_with_options(git_replace_usage, options);

	if (force && (list || delete))
		usage_with_options(git_replace_usage, options);

	/* Delete refs */
	if (delete) {
		if (argc < 1)
			usage_with_options(git_replace_usage, options);
		return for_each_replace_name(argv, delete_replace_ref);
	}

	/* Replace object */
	if (!list && argc) {
		if (argc != 2)
			usage_with_options(git_replace_usage, options);
		return replace_object(argv[0], argv[1], force);
	}

	/* List refs, even if "list" is not set */
	if (argc > 1)
		usage_with_options(git_replace_usage, options);
	if (force)
		usage_with_options(git_replace_usage, options);

	return list_replace_refs(argv[0]);
}