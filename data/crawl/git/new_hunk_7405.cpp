	if (argc > 1)
		die ("unrecognized argument: %s", argv[1]);

	/* assume HEAD if from a tty */
	if (!rev.pending.nr && isatty(0))
		add_head_to_pending(&rev);
	if (rev.pending.nr == 0) {
		read_from_stdin(&log);
	}
	else
		get_from_rev(&rev, &log);

	shortlog_output(&log);
	return 0;
}

void shortlog_output(struct shortlog *log)
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
					if (col != log->wrap)
						putchar('\n');
				}
				else
