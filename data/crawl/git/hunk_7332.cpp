 	o->df_conflict_entry = dfc;
 
 	if (len) {
-		posns = xmalloc(len * sizeof(struct tree_entry_list *));
-		for (i = 0; i < len; i++)
-			posns[i] = create_tree_entry_list(t+i);
-
-		if (unpack_trees_rec(posns, len, o->prefix ? o->prefix : "",
-				     o, &df_conflict_list)) {
-			if (o->gently) {
-				discard_cache();
-				read_cache();
-			}
-			return -1;
-		}
+		const char *prefix = o->prefix ? o->prefix : "";
+		struct traverse_info info;
+
+		setup_traverse_info(&info, prefix);
+		info.fn = unpack_callback;
+		info.data = o;
+
+		if (traverse_trees(len, t, &info) < 0)
+			return unpack_failed(o, NULL);
 	}
 
-	if (o->trivial_merges_only && o->nontrivial_merge) {
-		if (o->gently) {
-			discard_cache();
-			read_cache();
+	/* Any left-over entries in the index? */
+	if (o->merge) {
+		while (o->pos < active_nr) {
+			struct cache_entry *ce = active_cache[o->pos];
+			if (unpack_index_entry(ce, o) < 0)
+				return unpack_failed(o, NULL);
 		}
-		return o->gently ? -1 :
-			error("Merge requires file-level merging");
 	}
 
+	if (o->trivial_merges_only && o->nontrivial_merge)
+		return unpack_failed(o, "Merge requires file-level merging");
+
 	check_updates(o);
 	return 0;
 }