 		die("Path %s not in branch", s);
 	if (!*d) {	/* C "path/to/subdir" "" */
 		tree_content_replace(&b->branch_tree,
-			leaf.versions[1].sha1,
+			leaf.versions[1].oid.hash,
 			leaf.versions[1].mode,
 			leaf.tree);
 		return;
 	}
 	tree_content_set(&b->branch_tree, d,
-		leaf.versions[1].sha1,
+		leaf.versions[1].oid.hash,
 		leaf.versions[1].mode,
 		leaf.tree);
 }
