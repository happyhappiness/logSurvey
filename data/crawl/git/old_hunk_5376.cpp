		OPT_INTEGER('m', "mainline", &mainline, "parent number"),
		OPT_RERERE_AUTOUPDATE(&allow_rerere_auto),
		OPT_END(),
	};

	if (parse_options(argc, argv, NULL, options, usage_str, 0) != 1)
		usage_with_options(usage_str, options);

