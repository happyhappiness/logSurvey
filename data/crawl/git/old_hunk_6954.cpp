			continue;
		if (!pathspec_match(pattern, m, ce->name, 0))
			continue;
		path_list_insert(ce->name, list);
	}

	return report_path_error(m, pattern, prefix ? strlen(prefix) : 0);
}

static void add_remove_files(struct path_list *list)
{
	int i;
	for (i = 0; i < list->nr; i++) {
		struct stat st;
		struct path_list_item *p = &(list->items[i]);

		if (!lstat(p->path, &st)) {
			if (add_to_cache(p->path, &st, 0))
				die("updating files failed");
		} else
			remove_file_from_cache(p->path);
	}
}

