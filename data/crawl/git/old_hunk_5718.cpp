		if (!pathspec)
			die("invalid path specification");

		/* Checkout paths */
		if (opts.new_branch) {
			if (argc == 1) {
