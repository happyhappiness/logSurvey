	if (all && argc > 0)
		die(_("Paths with -a does not make sense."));

	if (status_format != STATUS_FORMAT_NONE)
		dry_run = 1;

