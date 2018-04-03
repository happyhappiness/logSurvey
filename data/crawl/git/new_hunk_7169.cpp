	}

	for (i = 0; i < dir.nr; i++)
		if (add_file_to_cache(dir.entries[i]->name, verbose))
			die("adding files failed");

 finish:
	if (active_cache_changed) {
