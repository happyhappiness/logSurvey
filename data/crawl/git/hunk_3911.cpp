 		if (0 < patch->is_new)
 			continue;
 
-		if (!get_sha1_blob(patch->old_sha1_prefix, sha1)) {
+		if (S_ISGITLINK(patch->old_mode)) {
+			if (get_sha1_hex(patch->old_sha1_prefix, sha1))
+				die("submoule change for %s without full index name",
+				    name);
+		} else if (!get_sha1_blob(patch->old_sha1_prefix, sha1)) {
 			; /* ok */
 		} else if (!patch->lines_added && !patch->lines_deleted) {
 			/* mode-only change: update the current */