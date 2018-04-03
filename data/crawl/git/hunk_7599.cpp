 	}
 }
 
+static void create_base_index(void)
+{
+	struct tree *tree;
+	struct unpack_trees_options opts;
+	struct tree_desc t;
+
+	if (initial_commit) {
+		discard_cache();
+		return;
+	}
+
+	memset(&opts, 0, sizeof(opts));
+	opts.head_idx = 1;
+	opts.index_only = 1;
+	opts.merge = 1;
+
+	opts.fn = oneway_merge;
+	tree = parse_tree_indirect(head_sha1);
+	if (!tree)
+		die("failed to unpack HEAD tree object");
+	parse_tree(tree);
+	init_tree_desc(&t, tree->buffer, tree->size);
+	unpack_trees(1, &t, &opts);
+}
+
 static char *prepare_index(int argc, const char **argv, const char *prefix)
 {
 	int fd;
-	struct tree *tree;
 	struct path_list partial;
 	const char **pathspec = NULL;
 
