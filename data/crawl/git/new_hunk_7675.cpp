		struct path_list *onelines = list.items[i].util;

		if (summary) {
			printf("%6d\t%s\n", onelines->nr, list.items[i].path);
		} else {
			printf("%s (%d):\n", list.items[i].path, onelines->nr);
			for (j = onelines->nr - 1; j >= 0; j--) {