	argc = parse_options(argc, argv, prefix, options, checkout_usage,
			     PARSE_OPT_KEEP_DASHDASH);

	/* we can assume from now on new_branch = !new_branch_force */
	if (opts.new_branch && opts.new_branch_force)
		die("-B cannot be used with -b");

	/* copy -B over to -b, so that we can just check the latter */
	if (opts.new_branch_force)
		opts.new_branch = opts.new_branch_force;

	if (patch_mode && (opts.track > 0 || opts.new_branch
			   || opts.new_branch_log || opts.merge || opts.force))
		die ("--patch is incompatible with all other options");
