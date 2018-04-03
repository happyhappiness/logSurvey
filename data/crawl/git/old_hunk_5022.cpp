			     0);
	if (argc > 0)
		usage_with_options(fmt_merge_msg_usage, options);
	if (message && !merge_summary) {
		char nl = '\n';
		write_in_full(STDOUT_FILENO, message, strlen(message));
		write_in_full(STDOUT_FILENO, &nl, 1);
		return 0;
	}

	if (inpath && strcmp(inpath, "-")) {
		in = fopen(inpath, "r");
