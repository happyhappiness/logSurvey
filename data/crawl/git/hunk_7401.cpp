 	if (!use_stdout)
 		realstdout = xfdopen(xdup(1), "w");
 
-	prepare_revision_walk(&rev);
+	if (prepare_revision_walk(&rev))
+		die("revision walk setup failed");
+	rev.boundary = 1;
 	while ((commit = get_revision(&rev)) != NULL) {
+		if (commit->object.flags & BOUNDARY) {
+			fprintf(stderr, "Boundary %s\n", sha1_to_hex(commit->object.sha1));
+			boundary_count++;
+			origin = (boundary_count == 1) ? commit : NULL;
+			continue;
+		}
+
 		/* ignore merges */
 		if (commit->parents && commit->parents->next)
 			continue;
