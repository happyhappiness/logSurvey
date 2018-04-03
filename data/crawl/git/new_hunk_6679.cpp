		die("invalid cache");
	}

	argc = parse_options(argc, argv, builtin_checkout_index_options,
			builtin_checkout_index_usage, 0);
	state.force = force;
	state.quiet = quiet;
	state.not_new = not_new;

	if (state.base_dir_len || to_tempfile) {
		/* when --prefix is specified we do not
