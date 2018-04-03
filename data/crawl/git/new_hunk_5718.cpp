		if (!pathspec)
			die("invalid path specification");

		if (patch_mode)
			return interactive_checkout(new.name, pathspec, &opts);

		/* Checkout paths */
		if (opts.new_branch) {
			if (argc == 1) {
