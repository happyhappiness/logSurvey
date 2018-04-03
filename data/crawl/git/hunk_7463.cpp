 		die("Unknown commit %s", limit);
 
 	/* reverse the list of commits */
-	prepare_revision_walk(&revs);
+	if (prepare_revision_walk(&revs))
+		die("revision walk setup failed");
 	while ((commit = get_revision(&revs)) != NULL) {
 		/* ignore merges */
 		if (commit->parents && commit->parents->next)
