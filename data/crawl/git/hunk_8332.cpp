 	int null_is_error = 0;
 	const char *head_points_at = resolve_ref("HEAD", sha1, 0, &flag);
 
+	if (verbose)
+		fprintf(stderr, "Checking HEAD link\n");
+
 	if (!head_points_at)
 		return error("Invalid HEAD");
 	if (!strcmp(head_points_at, "HEAD"))
