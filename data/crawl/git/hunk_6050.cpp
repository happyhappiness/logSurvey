 	info.revs = &revs;
 	info.bisect_show_flags = BISECT_SHOW_TRIED | BISECT_SHOW_STRINGED;
 
-	bisect_rev_setup(&revs, prefix);
-
-	if (prepare_revision_walk(&revs))
-		die("revision walk setup failed");
-	if (revs.tree_objects)
-		mark_edges_uninteresting(revs.commits, &revs, NULL);
-
-	revs.commits = find_bisection(revs.commits, &reaches, &all,
-				      !!skipped_sha1_nr);
+	bisect_common(&revs, prefix, &reaches, &all);
 
 	return show_bisect_vars(&info, reaches, all);
 }