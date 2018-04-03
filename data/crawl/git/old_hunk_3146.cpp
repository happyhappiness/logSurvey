	if (file_exists(git_path("MERGE_HEAD")))
		die_conclude_merge();

	if (run_fetch(repo, refspecs))
		return 1;

	if (opt_dry_run)
		return 0;

	get_merge_heads(&merge_heads);

	if (!merge_heads.nr)