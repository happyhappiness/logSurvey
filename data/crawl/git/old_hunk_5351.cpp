		usage_with_options(git_notes_usage, options);
	}

	if (!copy && from_stdin) {
		error("cannot use --stdin with %s subcommand.", argv[0]);
		usage_with_options(git_notes_usage, options);
	}

	if (copy) {
		const char *from_ref;
		if (from_stdin) {
			if (argc > 1) {
				error("too many parameters");
				usage_with_options(git_notes_usage, options);
			} else {
				return notes_copy_from_stdin(force);
			}
		}
		if (argc < 3) {
