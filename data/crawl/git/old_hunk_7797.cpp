	if (handle_diff_files_args(revs, argc, argv, &silent_on_removed))
		return -1;

	if (revs->diffopt.no_index) {
		if (revs->diffopt.nr_paths != 2)
			return error("need two files/directories with --no-index");
		if (queue_diff(&revs->diffopt, revs->diffopt.paths[0],
