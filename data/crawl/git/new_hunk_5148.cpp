		}
	}

	if (argc < 2) {
		error("too few parameters");
		usage_with_options(git_notes_copy_usage, options);
	}
	if (2 < argc) {
		error("too many parameters");
		usage_with_options(git_notes_copy_usage, options);
