 	if (prefix) {
 		struct cache_tree *subtree =
 			cache_tree_find(active_cache_tree, prefix);
+		if (!subtree)
+			die("git-write-tree: prefix %s not found", prefix);
 		hashcpy(sha1, subtree->sha1);
 	}
 	else