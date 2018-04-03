	} else {
		if (argc < 2)
			usage_with_options(blame_opt_usage, options);
		if (argc == 3 && is_a_rev(argv[argc - 1])) { /* (2b) */
			path = add_prefix(prefix, argv[1]);
			argv[1] = argv[2];
		} else {	/* (2a) */
			if (argc == 2 && is_a_rev(argv[1]) && !get_git_work_tree())
				die("missing <path> to blame");
			path = add_prefix(prefix, argv[argc - 1]);
		}
		argv[argc - 1] = "--";
	}

	revs.disable_stdin = 1;