	rollback_lock_file(lock);

	if (!strcmp(strategy, "recursive") || !strcmp(strategy, "subtree")) {
		int clean;
		struct commit *result;
		struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));
		int index_fd;
		struct commit_list *reversed = NULL;
		struct merge_options o;

		if (remoteheads->next) {
			error("Not handling anything other than two heads merge.");