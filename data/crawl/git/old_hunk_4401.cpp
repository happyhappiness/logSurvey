			OPT_END(),
		};
		if (parse_options_concat(options, ARRAY_SIZE(options), cp_extra))
			die("program error");
	}

	commit_argc = parse_options(argc, argv, NULL, options, usage_str,
