	if (all && argc > 0)
		die(_("Paths with -a does not make sense."));

	if (s->null_termination && status_format == STATUS_FORMAT_LONG)
		status_format = STATUS_FORMAT_PORCELAIN;
	if (status_format != STATUS_FORMAT_LONG)
		dry_run = 1;

	return argc;
