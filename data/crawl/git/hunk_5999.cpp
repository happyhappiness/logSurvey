 	struct commit_list **remotes = &remoteheads;
 
 	setup_work_tree();
+	if (file_exists(git_path("MERGE_HEAD")))
+		die("You have not concluded your merge. (MERGE_HEAD exists)");
 	if (read_cache_unmerged())
-		die("You are in the middle of a conflicted merge.");
+		die("You are in the middle of a conflicted merge."
+				" (index unmerged)");
 
 	/*
 	 * Check if we are _not_ on a detached HEAD, i.e. if there is a
