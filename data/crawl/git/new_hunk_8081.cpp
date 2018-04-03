	revs->diffopt.nr_paths = 2;
	revs->diffopt.no_index = 1;
	revs->max_count = -2;
	if (diff_setup_done(&revs->diffopt) < 0)
		die("diff_setup_done failed");
	return 0;
}
