 	}
 
 	/* Update remote server info if appropriate */
-	if (remote->has_info_refs && new_refs) {
-		if (info_ref_lock && remote->can_update_info_refs) {
+	if (repo->has_info_refs && new_refs) {
+		if (info_ref_lock && repo->can_update_info_refs) {
 			fprintf(stderr, "Updating remote server info\n");
 			if (!dry_run)
 				update_remote_info_refs(info_ref_lock);
