	tree = parse_tree_indirect(sha1);
	parse_tree(tree);
	init_tree_desc(&t, tree->buffer, tree->size);
	if (unpack_trees(1, &t, &opts) < 0)
		die(_("unable to checkout working tree"));

	if (write_cache(fd, active_cache, active_nr) ||
	    commit_locked_index(lock_file))
