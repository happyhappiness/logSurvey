	int pos = cache_name_pos(path, len);
	struct cache_entry *ce = pos < 0 ? NULL : active_cache[pos];

	if (ce && S_ISGITLINK(ntohl(ce->ce_mode)))
		return error("%s is already a gitlink, not replacing", path);

	return add_one_path(ce, path, len, st);
