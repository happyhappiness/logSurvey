	struct recent_command *rc;

	if (!rpt) {
		error_errno("can't write crash report %s", loc);
		free(loc);
		return;
	}
