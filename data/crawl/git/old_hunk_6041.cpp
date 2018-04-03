
static void bisect_rev_setup(struct rev_info *revs, const char *prefix)
{
	init_revisions(revs, prefix);
	revs->abbrev = 0;
	revs->commit_format = CMIT_FMT_UNSPECIFIED;

	/* argv[0] will be ignored by setup_revisions */
	ALLOC_GROW(rev_argv, rev_argv_nr + 1, rev_argv_alloc);
	rev_argv[rev_argv_nr++] = xstrdup("bisect_rev_setup");

	if (read_bisect_refs())
		die("reading bisect refs failed");

	ALLOC_GROW(rev_argv, rev_argv_nr + 1, rev_argv_alloc);
	rev_argv[rev_argv_nr++] = xstrdup("--");