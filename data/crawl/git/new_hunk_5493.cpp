{
	unsigned char sha1[20];
	struct tree *tree;
	int full_tree = 0;
	const struct option ls_tree_options[] = {
		OPT_BIT('d', NULL, &ls_options, "only show trees",
			LS_TREE_ONLY),
		OPT_BIT('r', NULL, &ls_options, "recurse into subtrees",
			LS_RECURSIVE),
		OPT_BIT('t', NULL, &ls_options, "show trees when recursing",
			LS_SHOW_TREES),
		OPT_SET_INT('z', NULL, &line_termination,
			    "terminate entries with NUL byte", 0),
		OPT_BIT('l', "long", &ls_options, "include object size",
			LS_SHOW_SIZE),
		OPT_BIT(0, "name-only", &ls_options, "list only filenames",
			LS_NAME_ONLY),
		OPT_BIT(0, "name-status", &ls_options, "list only filenames",
			LS_NAME_ONLY),
		OPT_SET_INT(0, "full-name", &chomp_prefix,
			    "use full path names", 0),
		OPT_BOOLEAN(0, "full-tree", &full_tree,
			    "list entire tree; not just current directory "
			    "(implies --full-name)"),
		OPT__ABBREV(&abbrev),
		OPT_END()
	};

	git_config(git_default_config, NULL);
	ls_tree_prefix = prefix;
	if (prefix && *prefix)
		chomp_prefix = strlen(prefix);

	argc = parse_options(argc, argv, prefix, ls_tree_options,
			     ls_tree_usage, 0);
	if (full_tree) {
		ls_tree_prefix = prefix = NULL;
		chomp_prefix = 0;
	}
	/* -d -r should imply -t, but -d by itself should not have to. */
	if ( (LS_TREE_ONLY|LS_RECURSIVE) ==
	    ((LS_TREE_ONLY|LS_RECURSIVE) & ls_options))
		ls_options |= LS_SHOW_TREES;

	if (argc < 1)
		usage_with_options(ls_tree_usage, ls_tree_options);
	if (get_sha1(argv[0], sha1))
		die("Not a valid object name %s", argv[0]);

	pathspec = get_pathspec(prefix, argv + 1);
	tree = parse_tree_indirect(sha1);
	if (!tree)
		die("not a tree object");