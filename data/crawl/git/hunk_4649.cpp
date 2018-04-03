 	opts.fn = oneway_merge;
 	tree = parse_tree_indirect(head_sha1);
 	if (!tree)
-		die("failed to unpack HEAD tree object");
+		die(_("failed to unpack HEAD tree object"));
 	parse_tree(tree);
 	init_tree_desc(&t, tree->buffer, tree->size);
 	if (unpack_trees(1, &t, &opts))
