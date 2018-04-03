		}

		for (i = 0; i < added.nr; i++) {
			const char *path = added.items[i].path;
			if (add_file_to_cache(path, verbose ? ADD_CACHE_VERBOSE : 0))
				die("updating index entries failed");
		}

		for (i = 0; i < deleted.nr; i++)
			remove_file_from_cache(deleted.items[i].path);

		if (active_cache_changed) {
			if (write_cache(newfd, active_cache, active_nr) ||
