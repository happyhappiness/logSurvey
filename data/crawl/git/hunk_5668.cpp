 	if (!found)
 		return 0;
 	fd = hold_lock_file_for_update(&packlock, git_path("packed-refs"), 0);
-	if (fd < 0)
+	if (fd < 0) {
+		unable_to_lock_error(git_path("packed-refs"), errno);
 		return error("cannot delete '%s' from packed refs", refname);
+	}
 
 	for (list = packed_ref_list; list; list = list->next) {
 		char line[PATH_MAX + 100];