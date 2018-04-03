			die("program error");
	}

	commit_argc = parse_options(argc, argv, NULL, options, usage_str, 0);
	if (commit_argc < 1)
		usage_with_options(usage_str, options);

	commit_argv = argv;
}

struct commit_message {
