
	/* we can assume from now on new_branch = !new_branch_force */
	if (opts.new_branch && opts.new_branch_force)
		die(_("-B cannot be used with -b"));

	/* copy -B over to -b, so that we can just check the latter */
	if (opts.new_branch_force)
		opts.new_branch = opts.new_branch_force;

	if (patch_mode && (opts.track > 0 || opts.new_branch
			   || opts.new_branch_log || opts.merge || opts.force))
		die (_("--patch is incompatible with all other options"));

	/* --track without -b should DWIM */
	if (0 < opts.track && !opts.new_branch) {
		const char *argv0 = argv[0];
		if (!argc || !strcmp(argv0, "--"))
			die (_("--track needs a branch name"));
		if (!prefixcmp(argv0, "refs/"))
			argv0 += 5;
		if (!prefixcmp(argv0, "remotes/"))
			argv0 += 8;
		argv0 = strchr(argv0, '/');
		if (!argv0 || !argv0[1])
			die (_("Missing branch name; try -b"));
		opts.new_branch = argv0 + 1;
	}

	if (opts.new_orphan_branch) {
		if (opts.new_branch)
			die(_("--orphan and -b|-B are mutually exclusive"));
		if (opts.track > 0)
			die(_("--orphan cannot be used with -t"));
		opts.new_branch = opts.new_orphan_branch;
	}

