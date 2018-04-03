	revs.diff = 1;
	revs.combine_merges = 0;
	revs.ignore_merges = 1;
	DIFF_OPT_SET(&revs.diffopt, RECURSIVE);

	if (add_pending_commit(head, &revs, 0))
		die("Unknown commit %s", head);
