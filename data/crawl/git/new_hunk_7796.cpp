	else
		revs->diffopt.paths = argv + argc - 2;
	revs->diffopt.nr_paths = 2;
	DIFF_OPT_SET(&revs->diffopt, NO_INDEX);
	revs->max_count = -2;
	if (diff_setup_done(&revs->diffopt) < 0)
		die("diff_setup_done failed");
