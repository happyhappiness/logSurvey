 	if (!pathspec || !*pathspec) {
 		fd = hold_locked_index(&index_lock, 1);
 		refresh_cache_or_die(refresh_flags);
-		if (write_cache(fd, active_cache, active_nr) ||
-		    commit_locked_index(&index_lock))
-			die("unable to write new_index file");
+		if (active_cache_changed) {
+			if (write_cache(fd, active_cache, active_nr) ||
+			    commit_locked_index(&index_lock))
+				die("unable to write new_index file");
+		} else {
+			rollback_lock_file(&index_lock);
+		}
 		commit_style = COMMIT_AS_IS;
 		return get_index_file();
 	}
