
	if (revs->reflog_info && revs->graph)
		die("cannot combine --walk-reflogs with --graph");
	if (!revs->reflog_info && revs->grep_filter.use_reflog_filter)
		die("cannot use --grep-reflog without --walk-reflogs");

	return left;
}
