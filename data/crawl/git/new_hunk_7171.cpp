
		for (i = 0; i < added.nr; i++) {
			const char *path = added.items[i].path;
			if (add_file_to_cache(path, verbose))
				die("updating index entries failed");
		}

		for (i = 0; i < deleted.nr; i++)
