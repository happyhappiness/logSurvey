static struct strategy *get_strategy(const char *name)
{
	int i;
	struct strbuf err;

	if (!name)
		return NULL;

	for (i = 0; i < ARRAY_SIZE(all_strategy); i++)
		if (!strcmp(name, all_strategy[i].name))
			return &all_strategy[i];

	strbuf_init(&err, 0);
	for (i = 0; i < ARRAY_SIZE(all_strategy); i++)
		strbuf_addf(&err, " %s", all_strategy[i].name);
	fprintf(stderr, "Could not find merge strategy '%s'.\n", name);
	fprintf(stderr, "Available strategies are:%s.\n", err.buf);
	exit(1);
}

static void append_strategy(struct strategy *s)
