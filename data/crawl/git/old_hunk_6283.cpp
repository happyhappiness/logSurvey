	printf(stringed ? "' &&\n" : "'\n");
}

int show_bisect_vars(struct rev_info *revs, int reaches, int all, int flags)
{
	int cnt;
	char hex[41] = "", *format;
	struct commit_list *tried;

	if (!revs->commits && !(flags & BISECT_SHOW_TRIED))
		return 1;
