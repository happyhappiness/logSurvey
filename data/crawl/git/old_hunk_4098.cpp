	int stage = opts->writeout_stage;
	int merge = opts->merge;
	int newfd;
	struct lock_file *lock_file = xcalloc(1, sizeof(struct lock_file));

	newfd = hold_locked_index(lock_file, 1);
	if (read_cache_preload(opts->pathspec) < 0)
