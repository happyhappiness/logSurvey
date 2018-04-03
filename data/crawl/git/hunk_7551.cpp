 	tree = parse_tree_indirect(ent->sha1);
 	if (!tree)
 		return error("bad tree object %s", tree_name);
-	if (read_tree(tree, 1, revs->prune_data))
-		return error("unable to read tree object %s", tree_name);
-	ret = diff_cache(revs, active_cache, active_nr, revs->prune_data,
-			 cached, match_missing);
+
+	memset(&opts, 0, sizeof(opts));
+	opts.head_idx = 1;
+	opts.index_only = cached;
+	opts.merge = 1;
+	opts.fn = oneway_diff;
+	opts.unpack_data = revs;
+
+	init_tree_desc(&t, tree->buffer, tree->size);
+	unpack_trees(1, &t, &opts);
+
 	diffcore_std(&revs->diffopt);
 	diff_flush(&revs->diffopt);
-	return ret;
+	return 0;
 }
 
 int do_diff_cache(const unsigned char *tree_sha1, struct diff_options *opt)
