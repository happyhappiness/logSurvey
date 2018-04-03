	return (e < 3 * x) ? n : n - 1;
}

static void show_tried_revs(struct commit_list *tried)
{
	printf("bisect_tried='");
	for (;tried; tried = tried->next) {
		char *format = tried->next ? "%s|" : "%s";
		printf(format, sha1_to_hex(tried->item->object.sha1));
	}
	printf("'\n");
}

int show_bisect_vars(struct rev_info *revs, int reaches, int all,
		     int show_all, int show_tried)
{
	int cnt;
	char hex[41] = "";
	struct commit_list *tried;

	if (!revs->commits && !show_tried)
		return 1;

	revs->commits = filter_skipped(revs->commits, &tried, show_all);

	/*
	 * revs->commits can reach "reaches" commits among
	 * "all" commits.  If it is good, then there are
