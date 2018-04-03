 			opts.head_idx = 1;
 	}
 
-	if (MAX_TREES < nr_trees)
-		die("I cannot read more than %d trees", MAX_TREES);
-
 	for (i = 0; i < nr_trees; i++) {
 		struct tree *tree = trees[i];
 		parse_tree(tree);