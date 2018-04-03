	if (prefix) {
		struct cache_tree *subtree =
			cache_tree_find(active_cache_tree, prefix);
		hashcpy(sha1, subtree->sha1);
	}
	else