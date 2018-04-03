	if (!merge_heads.nr)
		die_no_merge_candidates(repo, refspecs);

	return run_merge();
}