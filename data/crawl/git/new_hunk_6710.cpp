	int i = 0, ret;
	struct commit_list *j;
	struct strbuf buf;
	int index_fd;
	struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));

	index_fd = hold_locked_index(lock, 1);
	refresh_cache(REFRESH_QUIET);
	if (active_cache_changed &&
			(write_cache(index_fd, active_cache, active_nr) ||
			 commit_locked_index(lock)))
		return error("Unable to write index.");
	rollback_lock_file(lock);

	if (!strcmp(strategy, "recursive") || !strcmp(strategy, "subtree")) {
		int clean;
