	opts.dst_index = &the_index;

	opts.fn = oneway_merge;
	tree = parse_tree_indirect(get_object_hash(current_head->object));
	if (!tree)
		die(_("failed to unpack HEAD tree object"));
	parse_tree(tree);
