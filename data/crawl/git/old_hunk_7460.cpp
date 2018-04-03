	if (rev->early_output)
		setup_early_output(rev);

	prepare_revision_walk(rev);

	if (rev->early_output)
		finish_early_output(rev);
