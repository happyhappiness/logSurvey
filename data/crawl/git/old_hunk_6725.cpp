	return i;
}

static void show_list(const char *title, struct string_list *list)
{
	int i;

	if (!list->nr)
		return;

	printf(title, list->nr > 1 ? "es" : "");
	printf("\n    ");
	for (i = 0; i < list->nr; i++)
		printf("%s%s", i ? " " : "", list->items[i].string);
