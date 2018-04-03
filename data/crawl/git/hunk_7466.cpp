 {
 	struct commit *commit;
 
-	prepare_revision_walk(rev);
+	if (prepare_revision_walk(rev))
+		die("revision walk setup failed");
 	while ((commit = get_revision(rev)) != NULL) {
 		const char *author = NULL, *buffer;
 
