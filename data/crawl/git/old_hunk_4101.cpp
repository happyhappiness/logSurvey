		opts.new_branch = argv0 + 1;
	}

	if (opts.new_orphan_branch) {
		if (opts.new_branch)
			die(_("--orphan and -b|-B are mutually exclusive"));
		if (opts.track > 0)
			die(_("--orphan cannot be used with -t"));
		opts.new_branch = opts.new_orphan_branch;
	}

	if (conflict_style) {
		opts.merge = 1; /* implied */
		git_xmerge_config("merge.conflictstyle", conflict_style, NULL);
	}

	if (opts.force && opts.merge)
		die(_("git checkout: -f and -m are incompatible"));

	/*
	 * Extract branch name from command line arguments, so
	 * all that is left is pathspecs.
