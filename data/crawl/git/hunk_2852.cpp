 	return 0;
 }
 
+/**
+ * Merges a tree into the index. The index's stat info will take precedence
+ * over the merged tree's. Returns 0 on success, -1 on failure.
+ */
+static int merge_tree(struct tree *tree)
+{
+	struct lock_file *lock_file;
+	struct unpack_trees_options opts;
+	struct tree_desc t[1];
+
+	if (parse_tree(tree))
+		return -1;
+
+	lock_file = xcalloc(1, sizeof(struct lock_file));
+	hold_locked_index(lock_file, 1);
+
+	memset(&opts, 0, sizeof(opts));
+	opts.head_idx = 1;
+	opts.src_index = &the_index;
+	opts.dst_index = &the_index;
+	opts.merge = 1;
+	opts.fn = oneway_merge;
+	init_tree_desc(&t[0], tree->buffer, tree->size);
+
+	if (unpack_trees(1, t, &opts)) {
+		rollback_lock_file(lock_file);
+		return -1;
+	}
+
+	if (write_locked_index(&the_index, lock_file, COMMIT_LOCK))
+		die(_("unable to write new index file"));
+
+	return 0;
+}
+
 /**
  * Clean the index without touching entries that are not modified between
  * `head` and `remote`.
  */
 static int clean_index(const unsigned char *head, const unsigned char *remote)
 {
-	struct lock_file *lock_file;
 	struct tree *head_tree, *remote_tree, *index_tree;
 	unsigned char index[GIT_SHA1_RAWSZ];
-	struct pathspec pathspec;
 
 	head_tree = parse_tree_indirect(head);
 	if (!head_tree)
