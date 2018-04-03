	init_revisions(&rev, NULL);
	rev.abbrev = 0;
	rev.diffopt.output_format |= DIFF_FORMAT_NAME_STATUS;
	add_pending_object(&rev, head, NULL);
	run_diff_index(&rev, 0);
}
