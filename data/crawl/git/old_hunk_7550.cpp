	tree = parse_tree_indirect(tree_sha1);
	if (!tree)
		die("bad tree object %s", sha1_to_hex(tree_sha1));
	if (read_tree(tree, 1, opt->paths))
		return error("unable to read tree %s", sha1_to_hex(tree_sha1));
	return diff_cache(&revs, active_cache, active_nr, revs.prune_data,
			  1, 0);
}