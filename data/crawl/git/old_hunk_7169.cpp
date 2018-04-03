	}

	for (i = 0; i < dir.nr; i++)
		add_file_to_cache(dir.entries[i]->name, verbose);

 finish:
	if (active_cache_changed) {
