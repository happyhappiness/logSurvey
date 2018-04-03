 		refresh_cache_or_die(refresh_flags);
 		if (write_cache(fd, active_cache, active_nr) ||
 		    close_lock_file(&index_lock))
-			die("unable to write new_index file");
+			die(_("unable to write new_index file"));
 		commit_style = COMMIT_NORMAL;
 		return index_lock.filename;
 	}
