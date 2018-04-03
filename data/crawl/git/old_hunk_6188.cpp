	return result;
}

static void show_list(const char *title, struct string_list *list,
		      const char *extra_arg)
{
	int i;

	if (!list->nr)
		return;

	printf(title, list->nr > 1 ? "es" : "", extra_arg);
	printf("\n");
	for (i = 0; i < list->nr; i++)
		printf("    %s\n", list->items[i].string);
}

static int get_remote_ref_states(const char *name,
				 struct ref_states *states,
				 int query)
{
	struct transport *transport;
	const struct ref *ref;

	states->remote = remote_get(name);
	if (!states->remote)
