			     0);
	if (argc > 0)
		usage_with_options(fmt_merge_msg_usage, options);
	if (message && !shortlog_len) {
		char nl = '\n';
		write_in_full(STDOUT_FILENO, message, strlen(message));
		write_in_full(STDOUT_FILENO, &nl, 1);
		return 0;
	}
	if (shortlog_len < 0)
		die("Negative --log=%d", shortlog_len);

	if (inpath && strcmp(inpath, "-")) {
		in = fopen(inpath, "r");
