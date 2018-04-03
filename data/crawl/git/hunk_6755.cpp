 		}
 	}
 
-	if (merge_recursive(base == NULL ?
-				NULL : sha1_to_hex(base->object.sha1),
-				sha1_to_hex(head), "HEAD",
-				sha1_to_hex(next->object.sha1), oneline) ||
-			write_cache_as_tree(head, 0, NULL)) {
+	read_cache();
+	init_merge_options(&o);
+	o.branch1 = "HEAD";
+	o.branch2 = oneline;
+
+	head_tree = parse_tree_indirect(head);
+	next_tree = next ? next->tree : empty_tree();
+	base_tree = base ? base->tree : empty_tree();
+
+	clean = merge_trees(&o,
+			    head_tree,
+			    next_tree, base_tree, &result);
+
+	if (active_cache_changed &&
+	    (write_cache(index_fd, active_cache, active_nr) ||
+	     commit_locked_index(&index_lock)))
+		die("%s: Unable to write new index file", me);
+
+	if (!clean) {
 		add_to_msg("\nConflicts:\n\n");
-		read_cache();
 		for (i = 0; i < active_nr;) {
 			struct cache_entry *ce = active_cache[i++];
 			if (ce_stage(ce)) {