
	argc = parse_options(argc, argv, options, checkout_usage,
			     PARSE_OPT_KEEP_DASHDASH);
	if (argc) {
		arg = argv[0];
		if (get_sha1(arg, rev))
			;
		else if ((new.commit = lookup_commit_reference_gently(rev, 1))) {
			new.name = arg;
			setup_branch_path(&new);
			if (resolve_ref(new.path, rev, 1, NULL))
