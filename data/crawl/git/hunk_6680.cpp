 int read_index_unmerged(struct index_state *istate)
 {
 	int i;
-	struct cache_entry **dst;
-	struct cache_entry *last = NULL;
+	int unmerged = 0;
 
 	read_index(istate);
-	dst = istate->cache;
 	for (i = 0; i < istate->cache_nr; i++) {
 		struct cache_entry *ce = istate->cache[i];
-		if (ce_stage(ce)) {
-			remove_name_hash(ce);
-			if (last && !strcmp(ce->name, last->name))
-				continue;
-			cache_tree_invalidate_path(istate->cache_tree, ce->name);
-			last = ce;
+		struct cache_entry *new_ce;
+		int size, len;
+
+		if (!ce_stage(ce))
 			continue;
-		}
-		*dst++ = ce;
+		unmerged = 1;
+		len = strlen(ce->name);
+		size = cache_entry_size(len);
+		new_ce = xcalloc(1, size);
+		hashcpy(new_ce->sha1, ce->sha1);
+		memcpy(new_ce->name, ce->name, len);
+		new_ce->ce_flags = create_ce_flags(len, 0);
+		new_ce->ce_mode = ce->ce_mode;
+		if (add_index_entry(istate, new_ce, 0))
+			return error("%s: cannot drop to stage #0",
+				     ce->name);
+		i = index_name_pos(istate, new_ce->name, len);
 	}
-	istate->cache_nr = dst - istate->cache;
-	return !!last;
+	return unmerged;
 }
