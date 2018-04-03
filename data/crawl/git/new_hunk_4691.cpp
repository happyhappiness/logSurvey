
	newfd = hold_locked_index(lock_file, 1);
	if (read_cache_preload(pathspec) < 0)
		return error(_("corrupt index file"));

	if (source_tree)
		read_tree_some(source_tree, pathspec);
