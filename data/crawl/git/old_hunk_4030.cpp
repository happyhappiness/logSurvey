			     builtin_status_usage, 0);
	finalize_colopts(&s.colopts, -1);

	if (s.null_termination && status_format == STATUS_FORMAT_LONG)
		status_format = STATUS_FORMAT_PORCELAIN;

	handle_untracked_files_arg(&s);
	if (show_ignored_in_status)
