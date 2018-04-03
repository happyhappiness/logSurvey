
	if (revs->reflog_info && revs->graph)
		die("cannot combine --walk-reflogs with --graph");

	return left;
}
