 			       const struct ref *mapped_refs,
 			       const struct ref *remote_head_points_at,
 			       const char *branch_top,
-			       const char *msg)
+			       const char *msg,
+			       int check_connectivity)
 {
 	const struct ref *rm = mapped_refs;
 
-	if (check_everything_connected(iterate_ref_map, 0, &rm))
-		die(_("remote did not send all necessary objects"));
+	if (check_connectivity) {
+		if (check_everything_connected(iterate_ref_map, 0, &rm))
+			die(_("remote did not send all necessary objects"));
+	}
 
 	if (refs) {
 		write_remote_refs(mapped_refs);
