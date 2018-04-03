	DIFF_OPT_SET(&revs.diffopt, RECURSIVE);

	if (add_pending_commit(head, &revs, 0))
		die(_("Unknown commit %s"), head);
	if (add_pending_commit(upstream, &revs, UNINTERESTING))
		die(_("Unknown commit %s"), upstream);

	/* Don't say anything if head and upstream are the same. */
	if (revs.pending.nr == 2) {
