}

static void print_joined(const char *singular, const char *plural,
		struct list *list, struct strbuf *out)
{
	if (list->nr == 0)
		return;
	if (list->nr == 1) {
		strbuf_addf(out, "%s%s", singular, list->list[0]);
	} else {
		int i;
		strbuf_addstr(out, plural);
		for (i = 0; i < list->nr - 1; i++)
			strbuf_addf(out, "%s%s", i > 0 ? ", " : "", list->list[i]);
		strbuf_addf(out, " and %s", list->list[list->nr - 1]);
	}
}

static void shortlog(const char *name, unsigned char *sha1,
		struct commit *head, struct rev_info *rev, int limit,
		struct strbuf *out)
{
	int i, count = 0;
	struct commit *commit;
