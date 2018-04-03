	git_config(git_diff_basic_config, NULL); /* no "diff" UI options */

	if (read_cache() < 0)
		die (_("Could not read the index"));

	init_revisions(&rev, prefix);
	rev.diffopt.context = 7;
