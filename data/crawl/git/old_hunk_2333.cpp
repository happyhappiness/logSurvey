		usage_with_options(git_notes_list_usage, options);
	}

	t = init_notes_check("list");
	if (argc) {
		if (get_sha1(argv[0], object))
			die(_("Failed to resolve '%s' as a valid ref."), argv[0]);
