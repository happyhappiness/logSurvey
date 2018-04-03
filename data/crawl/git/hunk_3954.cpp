 		die_if_unmerged_cache(reset_type);
 
 	if (reset_type != SOFT) {
-		int err = reset_index_file(sha1, reset_type, quiet);
+		struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));
+		int newfd = hold_locked_index(lock, 1);
+		int err = reset_index(sha1, reset_type, quiet);
 		if (reset_type == KEEP && !err)
-			err = reset_index_file(sha1, MIXED, quiet);
+			err = reset_index(sha1, MIXED, quiet);
+		if (!err &&
+		    (write_cache(newfd, active_cache, active_nr) ||
+		     commit_locked_index(lock))) {
+			err = error(_("Could not write new index file."));
+		}
 		if (err)
 			die(_("Could not reset index file to revision '%s'."), rev);
 	}