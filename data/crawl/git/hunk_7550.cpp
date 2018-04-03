 	tree = parse_tree_indirect(tree_sha1);
 	if (!tree)
 		die("bad tree object %s", sha1_to_hex(tree_sha1));
-	if (read_tree(tree, 1, opt->paths))
-		return error("unable to read tree %s", sha1_to_hex(tree_sha1));
-	return diff_cache(&revs, active_cache, active_nr, revs.prune_data,
-			  1, 0);
+
+	memset(&opts, 0, sizeof(opts));
+	opts.head_idx = 1;
+	opts.index_only = 1;
+	opts.merge = 1;
+	opts.fn = oneway_diff;
+	opts.unpack_data = &revs;
+
+	init_tree_desc(&t, tree->buffer, tree->size);
+	unpack_trees(1, &t, &opts);
+	return 0;
 }