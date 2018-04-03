		return;

	printf(title, list->nr > 1 ? "es" : "", extra_arg);
	printf("\n    ");
	for (i = 0; i < list->nr; i++)
		printf("%s%s", i ? " " : "", list->items[i].string);
	printf("\n");
}

static int get_remote_ref_states(const char *name,
