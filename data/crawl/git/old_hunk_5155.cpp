
	if (opts.new_orphan_branch) {
		if (opts.new_branch)
			die("--orphan and -b are mutually exclusive");
		if (opts.track > 0)
			die("--orphan cannot be used with -t");
		opts.new_branch = opts.new_orphan_branch;
