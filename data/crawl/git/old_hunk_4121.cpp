	if (revs->combine_merges)
		revs->ignore_merges = 0;
	revs->diffopt.abbrev = revs->abbrev;
	if (diff_setup_done(&revs->diffopt) < 0)
		die("diff_setup_done failed");

	compile_grep_patterns(&revs->grep_filter);

