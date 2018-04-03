	printf("-%s\n", sha1_to_hex(commit->object.sha1));
}

static inline int log2i(int n)
{
	int log2 = 0;

	for (; n > 1; n >>= 1)
		log2++;

	return log2;
}

static inline int exp2i(int n)
{
	return 1 << n;
}

/*
 * Estimate the number of bisect steps left (after the current step)
 *
 * For any x between 0 included and 2^n excluded, the probability for
 * n - 1 steps left looks like:
 *
 * P(2^n + x) == (2^n - x) / (2^n + x)
 *
 * and P(2^n + x) < 0.5 means 2^n < 3x
 */
static int estimate_bisect_steps(int all)
{
	int n, x, e;

	if (all < 3)
		return 0;

	n = log2i(all);
	e = exp2i(n);
	x = all - e;

	return (e < 3 * x) ? n : n - 1;
}

static void show_tried_revs(struct commit_list *tried, int stringed)
{
	printf("bisect_tried='");
	for (;tried; tried = tried->next) {
		char *format = tried->next ? "%s|" : "%s";
		printf(format, sha1_to_hex(tried->item->object.sha1));
	}
	printf(stringed ? "' &&\n" : "'\n");
}

int show_bisect_vars(struct rev_list_info *info, int reaches, int all)
{
	int cnt, flags = info->bisect_show_flags;
	char hex[41] = "", *format;
	struct commit_list *tried;
	struct rev_info *revs = info->revs;

	if (!revs->commits && !(flags & BISECT_SHOW_TRIED))
		return 1;

	revs->commits = filter_skipped(revs->commits, &tried, flags & BISECT_SHOW_ALL);

	/*
	 * revs->commits can reach "reaches" commits among
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

	if (revs->commits)
		strcpy(hex, sha1_to_hex(revs->commits->item->object.sha1));

	if (flags & BISECT_SHOW_ALL) {
		traverse_commit_list(revs, show_commit, show_object, info);
		printf("------\n");
	}

	if (flags & BISECT_SHOW_TRIED)
		show_tried_revs(tried, flags & BISECT_SHOW_STRINGED);
	format = (flags & BISECT_SHOW_STRINGED) ?
		"bisect_rev=%s &&\n"
		"bisect_nr=%d &&\n"
		"bisect_good=%d &&\n"
		"bisect_bad=%d &&\n"
		"bisect_all=%d &&\n"
		"bisect_steps=%d\n"
		:
		"bisect_rev=%s\n"
		"bisect_nr=%d\n"
		"bisect_good=%d\n"
		"bisect_bad=%d\n"
		"bisect_all=%d\n"
		"bisect_steps=%d\n";
	printf(format,
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
	struct rev_info revs;
	struct rev_list_info info;
	int i;
	int read_from_stdin = 0;
	int bisect_list = 0;
	int bisect_show_vars = 0;
	int bisect_find_all = 0;
	int quiet = 0;
