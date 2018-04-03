		opts.new_branch = argv0 + 1;
	}

	if (opts.new_orphan_branch) {
		if (opts.new_branch)
			die("--orphan and -b are mutually exclusive");
		if (opts.track > 0 || opts.new_branch_log)
			die("--orphan cannot be used with -t or -l");
		opts.new_branch = opts.new_orphan_branch;
	}

	if (conflict_style) {
		opts.merge = 1; /* implied */
		git_xmerge_config("merge.conflictstyle", conflict_style, NULL);
