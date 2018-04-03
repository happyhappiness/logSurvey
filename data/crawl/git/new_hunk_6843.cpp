			die("invalid path specification");

		/* Checkout paths */
		if (opts.new_branch) {
			if (argc == 1) {
				die("git checkout: updating paths is incompatible with switching branches.\nDid you intend to checkout '%s' which can not be resolved as commit?", argv[0]);
			} else {
				die("git checkout: updating paths is incompatible with switching branches.");
			}
		}

		if (1 < !!opts.writeout_stage + !!opts.force + !!opts.merge)
			die("git checkout: --ours/--theirs, --force and --merge are incompatible when\nchecking out of the index.");

		return checkout_paths(source_tree, pathspec, &opts);
	}

