 					get_lock_file_path(lock->lk));
 			rollback_lock_file(&reflog_lock);
 		} else if (commit_lock_file(&reflog_lock)) {
-			status |= error("unable to commit reflog '%s' (%s)",
+			status |= error("unable to write reflog %s: %s",
 					log_file, strerror(errno));
 		} else if (update && commit_ref(lock)) {
 			status |= error("couldn't set %s", lock->ref_name);