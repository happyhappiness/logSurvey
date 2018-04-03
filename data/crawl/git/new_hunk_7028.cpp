		die("diff_setup_done failed");

	if (revs->grep_filter) {
		compile_grep_patterns(revs->grep_filter);
	}

