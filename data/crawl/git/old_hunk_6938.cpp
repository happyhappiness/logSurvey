				new.path = NULL;
			parse_commit(new.commit);
			source_tree = new.commit->tree;
			argv++;
			argc--;
		} else if ((source_tree = parse_tree_indirect(rev))) {
			argv++;
			argc--;
		}
	}

	if (argc && !strcmp(argv[0], "--")) {
		argv++;
		argc--;
	}

	if (!opts.new_branch && (opts.track != git_branch_track))
		die("git checkout: --track and --no-track require -b");

	if (opts.force && opts.merge)
		die("git checkout: -f and -m are incompatible");

	if (argc) {
		const char **pathspec = get_pathspec(prefix, argv);

