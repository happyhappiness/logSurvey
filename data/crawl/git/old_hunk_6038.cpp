
static void bisect_rev_setup(struct rev_info *revs, const char *prefix)
{
	int i;

	init_revisions(revs, prefix);
	revs->abbrev = 0;
	revs->commit_format = CMIT_FMT_UNSPECIFIED;

	if (read_bisect_refs())
		die("reading bisect refs failed");

	/* rev_argv.argv[0] will be ignored by setup_revisions */
	argv_array_push(&rev_argv, xstrdup("bisect_rev_setup"));
	argv_array_push_sha1(&rev_argv, current_bad_sha1, "%s");
