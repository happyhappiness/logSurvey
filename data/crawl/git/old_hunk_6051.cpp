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

