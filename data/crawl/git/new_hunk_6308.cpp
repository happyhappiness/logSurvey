	return (e < 3 * x) ? n : n - 1;
}

static int show_bisect_vars(int reaches, int all, int bisect_find_all)
{
	int cnt;
	char hex[41];

	if (!revs.commits)
		return 1;

	/*
	 * revs.commits can reach "reaches" commits among
	 * "all" commits.  If it is good, then there are
	 * (all-reaches) commits left to be bisected.
	 * On the other hand, if it is bad, then the set
	 * to bisect is "reaches".
	 * A bisect set of size N has (N-1) commits further
	 * to test, as we already know one bad one.
	 */
	cnt = all - reaches;
	if (cnt < reaches)
		cnt = reaches;
	strcpy(hex, sha1_to_hex(revs.commits->item->object.sha1));

	if (bisect_find_all) {
		traverse_commit_list(&revs, show_commit, show_object);
		printf("------\n");
	}

	printf("bisect_rev=%s\n"
	       "bisect_nr=%d\n"
	       "bisect_good=%d\n"
	       "bisect_bad=%d\n"
	       "bisect_all=%d\n"
	       "bisect_steps=%d\n",
	       hex,
	       cnt - 1,
	       all - reaches - 1,
	       reaches - 1,
	       all,
	       estimate_bisect_steps(all));

	return 0;
}

int cmd_rev_list(int argc, const char **argv, const char *prefix)
{
	struct commit_list *list;
