	read_cache();
	if (prefix)
		prune_cache(prefix);
	show_files(&dir, prefix);

	if (ps_matched) {
