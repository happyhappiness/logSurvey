
	hold_locked_index(lock_file, 1);
	if (read_cache_preload(&opts->pathspec) < 0)
		return error(_("corrupt index file"));

	if (opts->source_tree)
		read_tree_some(opts->source_tree, &opts->pathspec);
