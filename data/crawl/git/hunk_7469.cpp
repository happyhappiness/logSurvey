 	 * Set up the revision walk - this will move all commits
 	 * from the pending list to the commit walking list.
 	 */
-	prepare_revision_walk(revs);
+	if (prepare_revision_walk(revs))
+		die("revision walk setup failed");
 	walk_commit_list(revs);
 }
