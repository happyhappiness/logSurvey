
		for (i = 0; i < added.nr; i++) {
			const char *path = added.items[i].path;
			add_file_to_cache(path, verbose);
		}

		for (i = 0; i < deleted.nr; i++)
