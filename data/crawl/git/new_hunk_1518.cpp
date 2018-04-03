	if (help_format == HELP_FORMAT_NONE)
		help_format = parse_help_format(DEFAULT_HELP_FORMAT);

	argv[0] = check_git_cmd(argv[0]);

	switch (help_format) {
	case HELP_FORMAT_NONE:
