	struct lock_file *lock_file = xcalloc(1, sizeof(struct lock_file));

	newfd = hold_locked_index(lock_file, 1);
	read_cache();

	if (source_tree)
		read_tree_some(source_tree, pathspec);
