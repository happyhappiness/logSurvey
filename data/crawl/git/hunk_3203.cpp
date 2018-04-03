 		int save_errno = errno;
 
 		if (flags & LOCK_DIE_ON_ERROR)
-			exit(128);
+			die("failed to prepare '%s' for appending", path);
 		close(orig_fd);
 		rollback_lock_file(lk);
 		errno = save_errno;