	opts.dst_index = &the_index;

	opts.fn = oneway_merge;
	tree = parse_tree_indirect(current_head->object.sha1);
	if (!tree)
		die(_("failed to unpack HEAD tree object"));
	parse_tree(tree);
