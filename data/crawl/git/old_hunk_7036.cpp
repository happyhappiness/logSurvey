}

static void print_joined(const char *singular, const char *plural,
		struct list *list)
{
	if (list->nr == 0)
		return;
	if (list->nr == 1) {
		printf("%s%s", singular, list->list[0]);
	} else {
		int i;
		printf("%s", plural);
		for (i = 0; i < list->nr - 1; i++)
			printf("%s%s", i > 0 ? ", " : "", list->list[i]);
		printf(" and %s", list->list[list->nr - 1]);
	}
}

static void shortlog(const char *name, unsigned char *sha1,
		struct commit *head, struct rev_info *rev, int limit)
{
	int i, count = 0;
	struct commit *commit;
