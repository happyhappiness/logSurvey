
	init_revisions(&rev, prefix);

	if (no_index && argc != i + 2) {
		if (no_index == DIFF_NO_INDEX_IMPLICIT) {
			/*
			 * There was no --no-index and there were not two
			 * paths. It is possible that the user intended
			 * to do an inside-repository operation.
			 */
			fprintf(stderr, "Not a git repository\n");
			fprintf(stderr,
				"To compare two paths outside a working tree:\n");
		}
		/* Give the usage message for non-repository usage and exit. */
		usagef("git diff %s <path> <path>",
		       no_index == DIFF_NO_INDEX_EXPLICIT ?
		       "--no-index" : "[--no-index]");

	}
	if (no_index)
		/* If this is a no-index diff, just run it and exit there. */
		diff_no_index(&rev, argc, argv, prefix);

	/* Otherwise, we are doing the usual "git" diff */
	rev.diffopt.skip_stat_unmatch = !!diff_auto_refresh_index;