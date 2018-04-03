		usage_with_options(git_notes_usage, options);
	}

	if (copy) {
		const char *from_ref;
		if (argc < 3) {
			error("too few parameters");
			usage_with_options(git_notes_usage, options);
