	o.branch2 = better_branch_name(o.branch2);

	if (o.verbosity >= 3)
		printf(_("Merging %s with %s\n"), o.branch1, o.branch2);

	failed = merge_recursive_generic(&o, &h1, &h2, bases_count, bases, &result);
	if (failed < 0)