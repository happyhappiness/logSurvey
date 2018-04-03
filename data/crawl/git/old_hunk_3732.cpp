		if (verbose)
			die(_("cannot have both --quiet and --verbose"));
	}

	if (stdin_paths) {
		num_ignored = check_ignore_stdin_paths(prefix);
