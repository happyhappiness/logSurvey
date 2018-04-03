 			posns[i] = create_tree_entry_list(t+i);
 
 		if (unpack_trees_rec(posns, len, o->prefix ? o->prefix : "",
-				     o, &df_conflict_list))
+				     o, &df_conflict_list)) {
+			if (o->gently) {
+				discard_cache();
+				read_cache();
+			}
 			return -1;
+		}
 	}
 
-	if (o->trivial_merges_only && o->nontrivial_merge)
-		return error("Merge requires file-level merging");
+	if (o->trivial_merges_only && o->nontrivial_merge) {
+		if (o->gently) {
+			discard_cache();
+			read_cache();
+		}
+		return o->gently ? -1 :
+			error("Merge requires file-level merging");
+	}
 
 	check_updates(active_cache, active_nr, o);
 	return 0;
