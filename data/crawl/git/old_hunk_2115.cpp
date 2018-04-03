	struct commit **rev;
	int i = 0, rev_nr = 0;

	base = lookup_commit_reference_by_name(base_commit);
	if (!base)
		die(_("Unknown commit %s"), base_commit);

	ALLOC_ARRAY(rev, total);
	for (i = 0; i < total; i++)
