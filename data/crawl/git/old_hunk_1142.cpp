	else if (!strcmp(argv[0], "get-ref"))
		result = get_ref(argc, argv, prefix);
	else {
		result = error(_("Unknown subcommand: %s"), argv[0]);
		usage_with_options(git_notes_usage, options);
	}

