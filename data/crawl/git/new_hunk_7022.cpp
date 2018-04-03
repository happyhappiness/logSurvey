	 *
	 * The remaining are:
	 *
	 * (1) if dashdash_pos != 0, its either
	 *     "blame [revisions] -- <path>" or
	 *     "blame -- <path> <rev>"
	 *
	 * (2) otherwise, its one of the two:
	 *     "blame [revisions] <path>"
	 *     "blame <path> <rev>"
	 *
	 * Note that we must strip out <path> from the arguments: we do not
	 * want the path pruning but we may want "bottom" processing.
	 */
	if (dashdash_pos) {
		switch (argc - dashdash_pos - 1) {
		case 2: /* (1b) */
			if (argc != 4)
				usage_with_options(blame_opt_usage, options);
			/* reorder for the new way: <rev> -- <path> */
			argv[1] = argv[3];
			argv[3] = argv[2];
			argv[2] = "--";
			/* FALLTHROUGH */
		case 1: /* (1a) */
			path = add_prefix(prefix, argv[--argc]);
			argv[argc] = NULL;
			break;
		default:
			usage_with_options(blame_opt_usage, options);
		}
	} else {
		if (argc < 2)
			usage_with_options(blame_opt_usage, options);
		path = add_prefix(prefix, argv[argc - 1]);
		if (argc == 3 && !has_path_in_work_tree(path)) { /* (2b) */
			path = add_prefix(prefix, argv[1]);
			argv[1] = argv[2];
		}
		argv[argc - 1] = "--";

		setup_work_tree();
		if (!has_path_in_work_tree(path))
			die("cannot stat path %s: %s", path, strerror(errno));
	}

	setup_revisions(argc, argv, &revs, NULL);
	memset(&sb, 0, sizeof(sb));

	sb.revs = &revs;