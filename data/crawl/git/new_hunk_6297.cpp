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

int show_bisect_vars(struct rev_info *revs, int reaches, int all, int flags)
{
	int cnt;
	char hex[41] = "", *format;
	struct commit_list *tried;

	if (!revs->commits && !(flags & BISECT_SHOW_TRIED))
