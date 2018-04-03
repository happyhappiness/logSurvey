static struct strategy *get_strategy(const char *name)
{
	int i;

	if (!name)
		return NULL;

	for (i = 0; i < ARRAY_SIZE(all_strategy); i++)
		if (!strcmp(name, all_strategy[i].name))
			return &all_strategy[i];
	return NULL;
}

static void append_strategy(struct strategy *s)
