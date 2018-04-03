				new.path = NULL;
			parse_commit(new.commit);
			source_tree = new.commit->tree;
		} else
			source_tree = parse_tree_indirect(rev);

		if (!source_tree)                   /* case (1): want a tree */
			die("reference is not a tree: %s", arg);
		if (!has_dash_dash) {/* case (3 -> 1) */
			/*
			 * Do not complain the most common case
			 *	git checkout branch
			 * even if there happen to be a file called 'branch';
			 * it would be extremely annoying.
			 */
			if (argc)
				verify_non_filename(NULL, arg);
		}
		else {
			argv++;
			argc--;
		}
	}

no_reference:
	if (argc) {
		const char **pathspec = get_pathspec(prefix, argv);

