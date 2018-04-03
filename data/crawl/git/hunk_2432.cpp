 		if (cache_tree_update(&the_index, 0))
 			return error(_("Unable to update cache tree\n"));
 
-	return !hashcmp(active_cache_tree->sha1, get_object_hash(head_commit->tree->object));
+	return !hashcmp(active_cache_tree->sha1, head_commit->tree->object.oid.hash);
 }
 
 /*