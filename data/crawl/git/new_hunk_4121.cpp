	if (revs->combine_merges)
		revs->ignore_merges = 0;
	revs->diffopt.abbrev = revs->abbrev;
	diff_setup_done(&revs->diffopt);

	compile_grep_patterns(&revs->grep_filter);

