	else if (!strcmp(cleanup_arg, "strip"))
		cleanup_mode = CLEANUP_ALL;
	else
		die("Invalid cleanup mode %s", cleanup_arg);

	handle_untracked_files_arg(s);

	if (all && argc > 0)
		die("Paths with -a does not make sense.");
	else if (interactive && argc > 0)
		die("Paths with --interactive does not make sense.");

	if (null_termination && status_format == STATUS_FORMAT_LONG)
		status_format = STATUS_FORMAT_PORCELAIN;
