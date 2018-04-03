 	add_pending_object(&check_rev, o1, "o1");
 	add_pending_object(&check_rev, o2, "o2");
 	if (prepare_revision_walk(&check_rev))
-		die("revision walk setup failed");
+		die(_("revision walk setup failed"));
 
 	while ((commit = get_revision(&check_rev)) != NULL) {
 		/* ignore merges */
