	if (revs->reverse && revs->reflog_info)
		die("cannot combine --reverse with --walk-reflogs");

	/*
	 * Limitations on the graph functionality
	 */
	if (revs->reverse && revs->graph)
		die("cannot combine --reverse with --graph");

	if (revs->reflog_info && revs->graph)
		die("cannot combine --walk-reflogs with --graph");

	return left;
}

