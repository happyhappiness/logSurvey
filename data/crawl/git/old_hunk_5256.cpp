	return slop-1;
}

static int limit_list(struct rev_info *revs)
{
	int slop = SLOP;
	unsigned long date = ~0ul;
	struct commit_list *list = revs->commits;
	struct commit_list *newlist = NULL;
	struct commit_list **p = &newlist;

	while (list) {
		struct commit_list *entry = list;
