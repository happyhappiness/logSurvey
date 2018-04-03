			die("invalid path specification");

		/* Checkout paths */
		if (opts.new_branch || opts.merge) {
			if (argc == 1) {
				die("git checkout: updating paths is incompatible with switching branches.\nDid you intend to checkout '%s' which can not be resolved as commit?", argv[0]);
			} else {
				die("git checkout: updating paths is incompatible with switching branches.");
			}
		}

		return checkout_paths(source_tree, pathspec, &opts);
	}

	if (new.name && !new.commit) {
