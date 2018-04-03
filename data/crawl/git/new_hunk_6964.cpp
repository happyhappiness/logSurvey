	printf(title, list->nr > 1 ? "es" : "");
	printf("\n    ");
	for (i = 0; i < list->nr; i++)
		printf("%s%s", i ? " " : "", list->items[i].string);
	printf("\n");
}

