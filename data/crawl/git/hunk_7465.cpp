 	if (bisect_list)
 		revs.limited = 1;
 
-	prepare_revision_walk(&revs);
+	if (prepare_revision_walk(&revs))
+		die("revision walk setup failed");
 	if (revs.tree_objects)
 		mark_edges_uninteresting(revs.commits, &revs, show_edge);
 
