
	for (i = 0; i < rr->nr; i++) {
		int ret;
		const char *path = rr->items[i].string;
		const char *name = (const char *)rr->items[i].util;

		if (has_resolution(name)) {
			if (!merge(name, path)) {
				if (rerere_autoupdate)
					string_list_insert(path, &update);
				fprintf(stderr,
					"%s '%s' using previous resolution.\n",
					rerere_autoupdate
