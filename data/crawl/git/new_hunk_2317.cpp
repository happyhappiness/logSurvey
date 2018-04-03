
	if (log->sort_by_number)
		qsort(log->list.items, log->list.nr, sizeof(struct string_list_item),
		      log->summary ? compare_by_counter : compare_by_list);
	for (i = 0; i < log->list.nr; i++) {
		const struct string_list_item *item = &log->list.items[i];
		if (log->summary) {
			printf("%6d\t%s\n", (int)UTIL_TO_INT(item), item->string);
		} else {
			struct string_list *onelines = item->util;
			printf("%s (%d):\n", item->string, onelines->nr);
			for (j = onelines->nr - 1; j >= 0; j--) {
				const char *msg = onelines->items[j].string;

