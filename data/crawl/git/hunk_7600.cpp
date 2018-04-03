 
 	fd = hold_lock_file_for_update(&false_lock,
 				       git_path("next-index-%d", getpid()), 1);
-	discard_cache();
-	if (!initial_commit) {
-		tree = parse_tree_indirect(head_sha1);
-		if (!tree)
-			die("failed to unpack HEAD tree object");
-		if (read_tree(tree, 0, NULL))
-			die("failed to read HEAD tree object");
-	}
+
+	create_base_index();
 	add_remove_files(&partial);
 	refresh_cache(REFRESH_QUIET);
 