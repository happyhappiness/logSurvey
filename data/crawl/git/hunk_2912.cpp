 		cb.newlog = fdopen_lock_file(&reflog_lock, "w");
 		if (!cb.newlog) {
 			error("cannot fdopen %s (%s)",
-			      reflog_lock.filename.buf, strerror(errno));
+			      get_lock_file_path(&reflog_lock), strerror(errno));
 			goto failure;
 		}
 	}
