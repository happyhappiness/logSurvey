
	argc = parse_options(argc, argv, prefix, options, usage, 0);

	if (binary >= 0)
		fprintf_ln(stderr, _("The -b/--binary option has been a no-op for long time, and\n"
				"it will be removed. Please do not use it anymore."));

	if (read_index_preload(&the_index, NULL) < 0)
		die(_("failed to read the index"));
