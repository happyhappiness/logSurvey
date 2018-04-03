	}

	if (do_merge && argc != 1) {
		error(_("Must specify a notes ref to merge"));
		usage_with_options(git_notes_merge_usage, options);
	} else if (!do_merge && argc) {
		error(_("too many parameters"));
