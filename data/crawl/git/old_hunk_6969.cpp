{
	int i, j;
	if (log->sort_by_number)
		qsort(log->list.items, log->list.nr, sizeof(struct path_list_item),
			compare_by_number);
	for (i = 0; i < log->list.nr; i++) {
		struct path_list *onelines = log->list.items[i].util;

		if (log->summary) {
			printf("%6d\t%s\n", onelines->nr, log->list.items[i].path);
		} else {
			printf("%s (%d):\n", log->list.items[i].path, onelines->nr);
			for (j = onelines->nr - 1; j >= 0; j--) {
				const char *msg = onelines->items[j].path;

				if (log->wrap_lines) {
					int col = print_wrapped_text(msg, log->in1, log->in2, log->wrap);
