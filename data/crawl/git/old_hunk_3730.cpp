	if (show_non_matching && !verbose)
		die(_("--non-matching is only valid with --verbose"));

	if (stdin_paths) {
		num_ignored = check_ignore_stdin_paths(prefix);
	} else {
		num_ignored = check_ignore(prefix, argv);
		maybe_flush_or_die(stdout, "ignore to stdout");
	}

	return !num_ignored;
}