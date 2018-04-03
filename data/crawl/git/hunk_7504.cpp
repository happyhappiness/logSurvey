 		die("failed to unpack HEAD tree object");
 	parse_tree(tree);
 	init_tree_desc(&t, tree->buffer, tree->size);
-	unpack_trees(1, &t, &opts);
+	if (unpack_trees(1, &t, &opts))
+		exit(128); /* We've already reported the error, finish dying */
 }
 
 static char *prepare_index(int argc, const char **argv, const char *prefix)
