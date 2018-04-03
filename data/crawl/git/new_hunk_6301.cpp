
	return filtered;
}

int bisect_next_vars(const char *prefix)
{
	struct rev_info revs;
	int reaches = 0, all = 0;

	init_revisions(&revs, prefix);
	revs.abbrev = 0;
	revs.commit_format = CMIT_FMT_UNSPECIFIED;

	/* argv[0] will be ignored by setup_revisions */
	ALLOC_GROW(rev_argv, rev_argv_nr + 1, rev_argv_alloc);
	rev_argv[rev_argv_nr++] = xstrdup("bisect_rev_setup");

	if (read_bisect_refs())
		die("reading bisect refs failed");

	ALLOC_GROW(rev_argv, rev_argv_nr + 1, rev_argv_alloc);
	rev_argv[rev_argv_nr++] = xstrdup("--");

	setup_revisions(rev_argv_nr, rev_argv, &revs, NULL);

	revs.limited = 1;

	if (prepare_revision_walk(&revs))
		die("revision walk setup failed");
	if (revs.tree_objects)
		mark_edges_uninteresting(revs.commits, &revs, NULL);

	revs.commits = find_bisection(revs.commits, &reaches, &all,
				      !!skipped_sha1_nr);

	return show_bisect_vars(&revs, reaches, all, 0, 1);
}
