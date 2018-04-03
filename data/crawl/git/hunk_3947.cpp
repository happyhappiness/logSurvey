 			err = reset_index(sha1, MIXED, quiet);
 		if (err)
 			die(_("Could not reset index file to revision '%s'."), rev);
+
+		if (reset_type == MIXED) /* Report what has not been updated. */
+			update_index_refresh(
+				quiet ? REFRESH_QUIET : REFRESH_IN_PORCELAIN);
+
 		if (write_cache(newfd, active_cache, active_nr) ||
 		    commit_locked_index(lock))
 			die(_("Could not write new index file."));
