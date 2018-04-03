	struct cache_entry *ce;

	if (!verify_path(path))
		return error("Invalid path '%s'", path);

	len = strlen(path);
	size = cache_entry_size(len);
