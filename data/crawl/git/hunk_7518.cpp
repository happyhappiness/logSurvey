 
 	index_file = prepare_index(argc, argv, prefix);
 
-	if (!no_verify && run_hook(index_file, "pre-commit", NULL)) {
-		rollback_index_files();
-		return 1;
-	}
-
-	if (!prepare_log_message(index_file, prefix) && !in_merge &&
-	    !allow_empty && !(amend && is_a_merge(head_sha1))) {
-		run_status(stdout, index_file, prefix, 0);
+	/* Set up everything for writing the commit object.  This includes
+	   running hooks, writing the trees, and interacting with the user.  */
+	if (!prepare_to_commit(index_file, prefix)) {
 		rollback_index_files();
-		unlink(commit_editmsg);
 		return 1;
 	}
 
-	/*
-	 * Re-read the index as pre-commit hook could have updated it,
-	 * and write it out as a tree.
-	 */
-	discard_cache();
-	read_cache_from(index_file);
-	if (!active_cache_tree)
-		active_cache_tree = cache_tree();
-	if (cache_tree_update(active_cache_tree,
-			      active_cache, active_nr, 0, 0) < 0) {
-		rollback_index_files();
-		die("Error building trees");
-	}
-
 	/*
 	 * The commit object
 	 */
