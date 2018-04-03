	struct cache_entry *ce;

	if (!verify_path(path))
		return -1;

	len = strlen(path);
	size = cache_entry_size(len);
