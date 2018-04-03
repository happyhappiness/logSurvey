 		 */
 		int saved_errno = errno;
 		fprintf(stderr, _("Failed to fstat %s: %s"),
-			get_tempfile_path(&log_lock.tempfile),
+			get_tempfile_path(log_lock.tempfile),
 			strerror(saved_errno));
 		fflush(stderr);
 		commit_lock_file(&log_lock);
