
	if (argc) {
		const char **pathspec = get_pathspec(prefix, argv);

		if (!pathspec)
			die("invalid path specification");

		/* Checkout paths */
		if (opts.new_branch || opts.force || opts.merge) {
			if (argc == 1) {