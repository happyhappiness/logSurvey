{
	unsigned char sha1[20];
	struct tree *tree;

	git_config(git_default_config, NULL);
	ls_tree_prefix = prefix;
	if (prefix && *prefix)
		chomp_prefix = strlen(prefix);
	while (1 < argc && argv[1][0] == '-') {
		switch (argv[1][1]) {
		case 'z':
			line_termination = 0;
			break;
		case 'r':
			ls_options |= LS_RECURSIVE;
			break;
		case 'd':
			ls_options |= LS_TREE_ONLY;
			break;
		case 't':
			ls_options |= LS_SHOW_TREES;
			break;
		case 'l':
			ls_options |= LS_SHOW_SIZE;
			break;
		case '-':
			if (!strcmp(argv[1]+2, "name-only") ||
			    !strcmp(argv[1]+2, "name-status")) {
				ls_options |= LS_NAME_ONLY;
				break;
			}
			if (!strcmp(argv[1]+2, "long")) {
				ls_options |= LS_SHOW_SIZE;
				break;
			}
			if (!strcmp(argv[1]+2, "full-name")) {
				chomp_prefix = 0;
				break;
			}
			if (!strcmp(argv[1]+2, "full-tree")) {
				ls_tree_prefix = prefix = NULL;
				chomp_prefix = 0;
				break;
			}
			if (!prefixcmp(argv[1]+2, "abbrev=")) {
				abbrev = strtoul(argv[1]+9, NULL, 10);
				if (abbrev && abbrev < MINIMUM_ABBREV)
					abbrev = MINIMUM_ABBREV;
				else if (abbrev > 40)
					abbrev = 40;
				break;
			}
			if (!strcmp(argv[1]+2, "abbrev")) {
				abbrev = DEFAULT_ABBREV;
				break;
			}
			/* otherwise fallthru */
		default:
			usage(ls_tree_usage);
		}
		argc--; argv++;
	}
	/* -d -r should imply -t, but -d by itself should not have to. */
	if ( (LS_TREE_ONLY|LS_RECURSIVE) ==
	    ((LS_TREE_ONLY|LS_RECURSIVE) & ls_options))
		ls_options |= LS_SHOW_TREES;

	if (argc < 2)
		usage(ls_tree_usage);
	if (get_sha1(argv[1], sha1))
		die("Not a valid object name %s", argv[1]);

	pathspec = get_pathspec(prefix, argv + 2);
	tree = parse_tree_indirect(sha1);
	if (!tree)
		die("not a tree object");