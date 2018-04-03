	 * Other cases are errors.
	 */

	prefix = setup_git_directory_gently(&nongit);
	gitmodules_config();
	git_config(git_diff_ui_config, NULL);

	init_revisions(&rev, prefix);

	/* If this is a no-index diff, just run it and exit there. */
	diff_no_index(&rev, argc, argv, nongit, prefix);

	/* Otherwise, we are doing the usual "git" diff */
	rev.diffopt.skip_stat_unmatch = !!diff_auto_refresh_index;
