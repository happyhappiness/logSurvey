	if (rev->early_output)
		setup_early_output(rev);

	if (prepare_revision_walk(rev))
		die("revision walk setup failed");

	if (rev->early_output)
		finish_early_output(rev);
