	DIFF_OPT_SET(&revs->diffopt, NO_INDEX);

	revs->max_count = -2;
	if (diff_setup_done(&revs->diffopt) < 0)
		die("diff_setup_done failed");

	setup_diff_pager(&revs->diffopt);
	DIFF_OPT_SET(&revs->diffopt, EXIT_WITH_STATUS);
