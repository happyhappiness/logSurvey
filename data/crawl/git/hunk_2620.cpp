 {
 	if (ref->deletion)
 		print_ref_status('-', "[deleted]", ref, NULL, NULL, porcelain);
-	else if (is_null_sha1(ref->old_sha1))
+	else if (is_null_oid(&ref->old_oid))
 		print_ref_status('*',
 			(starts_with(ref->name, "refs/tags/") ? "[new tag]" :
 			"[new branch]"),
